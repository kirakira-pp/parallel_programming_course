// Copyright 2023 Nesterov Alexander

#ifndef MODULES_CORE_TESTS_TEST_TASK_HPP_
#define MODULES_CORE_TESTS_TEST_TASK_HPP_

#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include "core/include/task.hpp"

namespace ppc {
namespace test {

template<class T>
class TestTask : public ppc::core::Task {
 public:
    explicit TestTask(std::shared_ptr<ppc::core::TaskData> taskData_) : Task(taskData_) {}
    bool pre_processing() override {
        input_ = reinterpret_cast<T*>(taskData->inputs[0]);
        output_ = reinterpret_cast<T*>(taskData->outputs[0]);
        output_[0] = 0;
        return true;
    }

    bool validation() override {
        if (taskData->outputs_count[0] == 1) {
            return true;
        } else {
            return false;
        }
    }

    bool run() override {
        for (int i = 0; i < taskData->inputs_count[0]; i++) {
            output_[0] += input_[i];
        }
        return true;
    }

    bool post_processing() override {
        return true;
    }

 private:
    T *input_{};
    T *output_{};
};

}  // namespace test
}  // namespace ppc

#endif  // MODULES_CORE_TESTS_TEST_TASK_HPP_
