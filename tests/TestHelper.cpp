#include "TestHelper.hpp"

#include <experimental/filesystem>
#include <iostream>

std::string TestHelper::sp;
std::string TestHelper::pth;
std::list<std::string> TestHelper::docs;

void TestHelper::init()
{
    //        start sp based on the user's platform
#ifdef _WIN32
    sp = "\\";
#else
    sp = "/";
#endif

    // start pth based on the current path position + test files path
    auto current = std::experimental::filesystem::current_path();
    auto str     = current.string();
    auto it      = str.find("build");
    if (it == std::string::npos) {
        return;
    }
    str.erase(it, str.size());
    pth = str + "qt-ts-csv" + sp + "tests" + sp + "files" + sp;
}
void TestHelper::teardown()
{
    while (!docs.empty()) {
        std::experimental::filesystem::remove(docs.front());
        docs.pop_front();
    }
}
std::string TestHelper::fullPath(const std::string &fldr)
{
    return pth + fldr + sp;
}
void TestHelper::pushDocs(const std::string &doc)
{
    docs.push_front(doc);
}
std::string TestHelper::findDiff(const std::string &docReaded,
                                 const std::string &expected)
{
    std::string diffs;
    unsigned long j = 0;

    for (char i : expected) {
        if (i == docReaded[j])
            ++j;
        else
            diffs += i;
    }
    std::cout << "docReaded: " << std::endl << docReaded << std::endl;
    std::cout << "expected: " << std::endl << expected << std::endl;

    std::cout << "docReaded size: " << docReaded.size() << std::endl;
    std::cout << "expected size: " << expected.size() << std::endl;
    std::cout << "j: " << j << ", diffs.size: " << diffs.size() << std::endl
              << std::endl;

    return diffs;
}
