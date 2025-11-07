#!/bin/bash
# format-multi.sh
# 使用 .clang-format 格式化多个目录下的 C/C++ 源码文件
# 无论在哪个目录执行，都能正确运行

# 获取脚本所在的目录（项目根目录）
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
CLANG_FORMAT=clang-format

# 定义需要格式化的目录列表（相对于项目根目录）
DIRS=(
    "algo_service/src"
    "tests/"
)

# 检查 clang-format 是否安装
if ! command -v $CLANG_FORMAT &> /dev/null; then
    echo "❌ 错误: 未找到 clang-format，请先安装：sudo apt install clang-format"
    exit 1
fi

# 循环处理每个目录
for dir in "${DIRS[@]}"; do
    TARGET_DIR="$SCRIPT_DIR/$dir"
    if [ -d "$TARGET_DIR" ]; then
        echo "正在格式化目录: $TARGET_DIR"
        find "$TARGET_DIR" -type f \( \
            -name "*.c" -o -name "*.cc" -o -name "*.cpp" -o \
            -name "*.h" -o -name "*.hpp" \) \
            -exec $CLANG_FORMAT -i --style=file {} \;
    else
        echo "⚠️ 跳过目录: $TARGET_DIR (不存在)"
    fi
done

echo "✅ 格式化完成"
