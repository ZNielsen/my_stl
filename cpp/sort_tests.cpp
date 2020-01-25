////////////////////////////////////////////////////////////////////////////////
//  File:   sort_tests.cpp
//
//  © Zach Nielsen 2020
//  Tests for the different sorting algorithms
//

////////////////////////////////////////////////////////////////////////////////
//  INCLUDES
////////////////////////////////////////////////////////////////////////////////
#include <gtest/gtest.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>

#include "mergesort.h"
#include "quicksort.h"
#include "data/sort_vectors.h"

#include <vector>

////////////////////////////////////////////////////////////////////////////////
//  CODE
////////////////////////////////////////////////////////////////////////////////

void generate_test_data(void);


class Sort_Tests : public testing::Test
{
  public:
    static constexpr int NUM_TO_SORT {100};
    static const char DATA_FILE[];
  protected:
    virtual void SetUp() override {
    }

    virtual void TearDown() override {
    }
  private:
};
const char Sort_Tests::DATA_FILE[] = "../../data/sort_vectors.h";

TEST(Sort_Tests, quicksort_Test)
{
    // generate_test_data();
    auto in = random_data;
    auto exp = random_data;
    quicksort(in);
    std::sort(exp.begin(), exp.end());
    EXPECT_EQ(in, exp);
}

TEST(Sort_Tests, mergesort_Test)
{
    // generate_test_data();
    auto in = random_data;
    auto exp = random_data;
    mergesort(in);
    std::sort(exp.begin(), exp.end());
    EXPECT_EQ(in, exp);
}

void generate_test_data(void)
{
    const auto generate_custom_data = true;
    const auto mod_num {10};
    if (generate_custom_data) {
        std::cout << "Generating new data" << std::endl;
        std::ofstream f;
        f.open(Sort_Tests::DATA_FILE, std::ios::out | std::ios::trunc);
        f << "#pragma once\n";
        f << "#include <vector>\n";

        f << "std::vector<int> in_order_data = {\n\t";
        for (int num=-(Sort_Tests::NUM_TO_SORT/2); num<=(Sort_Tests::NUM_TO_SORT/2); num++) {
            f << num << ", ";
            if (0 == num % mod_num) { f << "\n\t"; }
        }
        f << "0};\n";

        f << "std::vector<int> backward_order_data = {\n\t";
        for (int num=(Sort_Tests::NUM_TO_SORT/2); num >= -(Sort_Tests::NUM_TO_SORT/2); num--) {
            f << num << ", ";
            if (0 == num % mod_num) { f << "\n\t"; }
        }
        f << "0};\n";

        std::srand (uint(std::time(NULL)));
        f << "std::vector<int> random_data = {\n\t";
        for (int num=0; num<=Sort_Tests::NUM_TO_SORT; num++) {
            f << rand() << ", ";
            if (0 == num % mod_num) { f << "\n\t"; }
        }
        f << "0};\n";

        f.close();

        std::cout << "Done generating data" << std::endl;
    }
}
