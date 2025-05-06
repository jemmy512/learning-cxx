add_rules("mode.debug", "mode.release")
set_encodings("utf-8")
set_warnings("all")
set_kind("binary")
add_includedirs("../utils/")

-- 格式化输出
target("00_hello_world")
    add_files("00_hello_world/main.cpp")

-- 变量与运算符
target("01_variable_add")
    add_files("01_variable_add/main.cpp")

-- 函数、声明和定义
target("02_function")
    add_files("02_function/main.cpp")

-- 形参实参
target("03_argument_parameter")
    add_files("03_argument_parameter/main.cpp")

-- static 关键字
target("04_key_static")
    add_files("04_key_static/main.cpp")

-- constexpr 编译时常量和运算
target("05_key_cast")
    add_files("05_key_cast/main.cpp")

target("05_key_const")
    add_files("05_key_const/main.cpp")

target("05_key_constexpr")
    add_files("05_key_constexpr/main.cpp")

-- 数组
target("06_array")
    add_files("06_array/main.cpp")

-- 循环
target("07_loop")
    add_files("07_loop/main.cpp")

-- 指针
target("08_pointer")
    add_files("08_pointer/main.cpp")

target("08_pointer_func")
    add_files("08_pointer_func/main.cpp")

target("08_pointer_smart")
    add_files("08_pointer_smart/main.cpp")

-- 枚举/联合体
target("09_enum_union")
    add_files("09_enum_union/main.cpp")

-- “普通”类型
target("10_trivial")
    add_files("10_trivial/main.cpp")

-- 方法
target("11_method")
    add_files("11_method/main.cpp")

-- const 修饰方法
target("12_method_const")
    add_files("12_method_const/main.cpp")

-- 类
target("13_class")
    add_files("13_class/main.cpp")

-- 析构器
target("14_class_destruct")
    add_files("14_class_destruct/main.cpp")

-- 复制构造函数
target("15_class_clone")
    add_files("15_class_clone/main.cpp")

-- 移动语义
target("16_class_move")
    add_files("16_class_move/main.cpp")

-- 派生
target("17_class_derive")
    add_files("17_class_derive/main.cpp")

-- 虚函数
target("18_class_virtual")
    add_files("18_class_virtual/main.cpp")

-- 虚析构函数
target("19_class_virtual_destruct")
    add_files("19_class_virtual_destruct/main.cpp")

-- 函数模板
target("20_function_template")
    add_files("20_function_template/main.cpp")

-- 习题：用于编译器的运行时类型
target("21_runtime_datatype")
    add_files("21_runtime_datatype/main.cpp")

-- 类模板
target("22_class_template")
    add_files("22_class_template/main.cpp")

-- 模板非类型实参
target("23_template_const")
    add_files("23_template_const/main.cpp")

-- std::array
target("24_std_array")
    add_files("24_std_array/main.cpp")

-- std::vector
target("25_std_vector")
    add_files("25_std_vector/main.cpp")

-- std::vector<bool>
target("26_std_vector_bool")
    add_files("26_std_vector_bool/main.cpp")

-- 习题：步长计算
target("27_strides")
    add_files("27_strides/main.cpp")

-- std::string
target("28_std_string")
    add_files("28_std_string/main.cpp")

-- std::map
target("29_std_map")
    add_files("29_std_map/main.cpp")

-- std::transform
target("30_std_unique_ptr")
    add_files("30_std_unique_ptr/main.cpp")

-- std::accumulate
target("31_std_shared_ptr")
    add_files("31_std_shared_ptr/main.cpp")

-- std::transform
target("32_std_transform")
    add_files("32_std_transform/main.cpp")

-- std::accumulate
target("33_std_accumulate")
    add_files("33_std_accumulate/main.cpp")

target("34_c_string")
    add_files("34_c_string/main.cpp")

-- TODO: lambda; deque; forward_list; fs; thread; mutex;
