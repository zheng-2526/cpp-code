# C++ 代码合集

按用途整理 C++ 基础练习、算法、数据结构和课程作业。

## 目录

```text
cpp-code/
├── basics/              # C++ 基础练习
├── algorithms/          # 算法
│   ├── sorting/          # 排序算法
│   └── searching/        # 查找算法
├── data-structures/     # 数据结构
└── coursework/          # 课程作业
```

每个目录中的 README.md 用来说明用途，也让暂时没有代码的目录能够保存在 Git 中。

## 添加代码

- 基础练习放入 `basics/`。
- 算法按类型放入 `algorithms/` 的子目录。
- 数据结构实现放入 `data-structures/`。
- 课程作业可以按课程和次数分类，例如 `coursework/cpp/homework-01/main.cpp`。

多个独立程序如果各自包含 `main()`，请分别编译运行。
编译输出建议放入 `build/`，该目录已由 `.gitignore` 排除。

## 日常同步

在本地没有未提交改动时，开始编程前获取远程更新：

```powershell
git pull --ff-only
```

保存代码后，在仓库目录中查看、提交并推送改动：

```powershell
git status
git add .
git commit -m "说明本次修改"
git push
```

`git commit` 将版本保存在本地，`git push` 将已提交的版本同步到 GitHub。
