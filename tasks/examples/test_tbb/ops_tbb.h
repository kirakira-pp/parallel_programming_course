// Copyright 2023 Nesterov Alexander
#ifndef TASKS_EXAMPLES_TEST_TBB_OPS_TBB_H_
#define TASKS_EXAMPLES_TEST_TBB_OPS_TBB_H_

#include <vector>
#include <string>

std::vector<int> getRandomVector(int sz);
int getParallelOperations(std::vector<int> vec, const std::string& ops);
int getSequentialOperations(std::vector<int> vec, const std::string& ops);

#endif  // TASKS_EXAMPLES_TEST_TBB_OPS_TBB_H_
