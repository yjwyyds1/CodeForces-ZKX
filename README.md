# Zhengai - Competitive Programming Workspace

Codeforces 刷题工作区，包含自动化测试管线。

## 文件说明

| 文件 | 用途 |
|------|------|
| `1.cpp` | 主解法（线段树 Segment Tree Beats，区间 chmin/chmax/add + 区间和/最值查询） |
| `2.cpp` | 数据生成器，生成测试用例写入 `zkx.in` |
| `3.cpp` | 暴力/正确解法，生成标准答案写入 `zkx.ans` |
| `a.cpp` | Nailoong vs. Bombloong 1 通信题解法 |
| `nailoong_vs_bombloong1_testing_tool.py` | Codeforces 官方通信题本地测试工具 |
| `zkx.in` / `zkx.out` / `zkx.ans` | 输入、输出、答案文件 |

## 自动化测试流水线

```
数据生成 (2.cpp) → 答案生成 (3.cpp) → 运行验证 (1.cpp)
```

### 脚本说明

| 脚本 | 作用 |
|------|------|
| `2.bat` | 编译运行 `2.cpp`，生成 `zkx.in` |
| `3.bat` | 编译运行 `3.cpp`，读取 `zkx.in`，生成 `zkx.ans` |
| `1.bat` | 编译运行 `1.cpp`，读取 `zkx.in`，输出到 `zkx.out`，并与 `zkx.ans` 对比 |
| `x.bat` | 一键运行完整管线：`2.bat → 3.bat → 1.bat` |

### 使用方法

**运行完整测试：**
```bat
x.bat
```

**单独运行：**
```bat
2.bat    # 仅生成测试数据
3.bat    # 仅生成标准答案
1.bat    # 运行解法并判断 Accepted/Wrong Answer
```

**Nailoong vs. Bombloong 通信题测试：**
```bash
g++ a.cpp -o a.exe
python nailoong_vs_bombloong1_testing_tool.py data.in ./a.exe
```
