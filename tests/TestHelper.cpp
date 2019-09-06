#include "TestHelper.hpp"

#include <exception>
#include <experimental/filesystem>

TestHelper TestHelper::instance;
// std::string TestHelper::fullPath(const std::string &fldr)
//{
//    return pth + fldr + sp;
//}

// std::string TestHelper::findDiff(const std::string &docReaded,
//                                 const std::string &expected)
//{
//    std::string diffs;
//    unsigned long j = 0;

//    for (char i : expected) {
//        if (i == docReaded[j])
//            ++j;
//        else
//            diffs += i;
//    }
//    std::cout << "docReaded: " << std::endl << docReaded << std::endl;
//    std::cout << "expected: " << std::endl << expected << std::endl;

//    std::cout << "docReaded size: " << docReaded.size() << std::endl;
//    std::cout << "expected size: " << expected.size() << std::endl;
//    std::cout << "j: " << j << ", diffs.size: " << diffs.size() << std::endl
//              << std::endl;

//    return diffs;
//}
// bool TestHelper::ToRun(const std::string &s)
//{
//    for (std::string i : to) {
//        if (i == s)
//            return true;
//    }
//    return false;
//}

std::string TestHelper::full_path(const std::string &fldr)
{
    return TestHelper::instance.pth + fldr + TestHelper::instance.sp;
}

TestHelper::TestHelper()
{
#ifdef _WIN32
    sp = "\\";
#else
    sp = "/";
#endif

    auto current = std::experimental::filesystem::current_path();
    auto str     = current.string();
    auto it      = str.find("build");
    if (it == std::string::npos) {
        throw std::logic_error("can't find build directory, "
                               "please call it build<optional>");
    }

    str.erase(it, str.size());
    pth = str + "qt-ts-csv" + sp + "tests" + sp + "files" + sp;
}

TestHelper::~TestHelper()
{
    for (auto &doc : docs) {
        std::experimental::filesystem::remove(doc);
    }

    docs.clear();
}
