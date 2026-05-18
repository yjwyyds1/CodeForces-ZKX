@echo off
setlocal enabledelayedexpansion

REM 配置参数
set "SOURCE_FILE=2.cpp"
set "EXECUTABLE=2.exe"
set "OUTPUT_FILE=zkx.in"
set "TIMEOUT_SECONDS=5"

REM 编译
echo Compiling...
g++ -std=c++17 -O2 -Wall %SOURCE_FILE% -o %EXECUTABLE%
if not errorlevel 0 (
  powershell -Command "Write-Host 'Compilation failed' -ForegroundColor Red"
  pause
  exit /b 1
)

REM 测试运行并计时
powershell -Command "Write-Host 'Pending' -ForegroundColor DarkGray"

REM 运行程序并设置超时限制
set /a "timeout_ms=TIMEOUT_SECONDS * 1000"

REM 修改后的PowerShell命令 - 不需要重定向输入
set "PS_CMD=$process = Start-Process -FilePath '%EXECUTABLE%' -RedirectStandardOutput '%OUTPUT_FILE%' -PassThru -NoNewWindow; $exited = $process.WaitForExit(%TIMEOUT_SECONDS% * 1000); if (-not $exited) { $process.Kill(); Write-Output 'TIMEOUT,1' } else { $time = $process.TotalProcessorTime.TotalMilliseconds; $exitCode = $process.ExitCode; Write-Output ($time.ToString('F0') + ',' + $exitCode) }"

for /f "tokens=1,2 delims=," %%a in ('powershell -Command "!PS_CMD!"') do (
  set "run_time=%%a"
  set "exit_code=%%b"
)

REM 检查是否超时
if "!run_time!"=="TIMEOUT" (
  powershell -Command "Write-Host 'Time limit exceeded' -ForegroundColor Red"
  echo Time: !timeout_ms! ms
  exit /b 1
)

REM 检查退出代码
if !exit_code! neq 0 (
  powershell -Command "Write-Host 'Runtime error (exit code: !exit_code!)' -ForegroundColor Red"
  exit /b 1
)

REM 检查文件是否存在且不为空
if not exist %OUTPUT_FILE% (
  powershell -Command "Write-Host 'Runtime error (no output generated)' -ForegroundColor Red"
  exit /b 1
)

for %%I in (%OUTPUT_FILE%) do if %%~zI equ 0 (
  powershell -Command "Write-Host 'Runtime error (empty output)' -ForegroundColor Red"
  exit /b 1
)

REM 输出运行时间
echo Time: !run_time! ms

powershell -Command "Write-Host 'Print Successful' -ForegroundColor Green"

endlocal