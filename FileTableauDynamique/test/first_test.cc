/**
 * \file FileTesteur.cpp
 * \brief Tests de la classe File en format Google Test
 * \author N/A
 * \version 0.3
 * \date N/A
 *
 * Représentation dans un tableau dynamique
 */

#include "gtest/gtest.h"
#include "File.h"
#include <sstream>

using namespace Laboratoire-Pile-File
static const int val1 = 10;
static const int val1 = 10;
static const int val1 = 10;

class FileTest: public ::Testing::Test {
public:
    virtual void SetUp() {
        file2.enfiler(val1);
        file2.enfiler(val2);
        file2.enfiler(val3);
    }
    // virtual void TearDown() {}
    File<int> file1;
    File<int> file2;
};

// ---------------------- (8) -------------------------
// ----------------------------------------------------
// void File<T>::enfiler(const T & p_element)
// T File<T>::defiler()
TEST_F(FileTest, FileVideOK) {
    
}