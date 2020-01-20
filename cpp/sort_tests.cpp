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

#include <vector>

////////////////////////////////////////////////////////////////////////////////
//  CODE
////////////////////////////////////////////////////////////////////////////////

class Sort_Tests : public testing::Test
{
  private:
    static constexpr uint NUM_TO_SORT {100000};
  protected:
    virtual void SetUp() override {
        const auto generate_custom_data = false;
        if (generate_custom_data) {
            std::ofstream f;
            f.open("./data/sort_vectors.h", std::ios::out | std::ios::trunc);
            f << "#pragma once\n";

            f << "std::vector<int> in_order_data = {\n";
            for (auto num=-(NUM_TO_SORT/2); num<=(NUM_TO_SORT/2); num++) {
                f << "\t" << num << ",\n";
            }
            f << "};\n";

            f << "std::vector<int> backward_order_data = {\n";
            for (auto num=(NUM_TO_SORT/2); num>=-(NUM_TO_SORT/2); num--) {
                f << "\t" << num << ",\n";
            }
            f << "};\n";

            std::srand (uint(std::time(NULL)));
            f << "std::vector<int> random_data = {\n";
            for (uint num=0; num<=NUM_TO_SORT; num++) {
                f << "\t" << rand() << ",\n";
            }
            f << "};\n";

            f.close();
        }
    }

    virtual void TearDown() override {
    }
  public:
};

TEST(Sort_Tests, quicksort_Test)
{
    ASSERT_TRUE(true);
}
