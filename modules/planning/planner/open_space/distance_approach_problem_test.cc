/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 **/
#include "modules/planning/planner/open_space/distance_approach_problem.h"

#include "gtest/gtest.h"

namespace apollo {
namespace planning {

class DistanceApproachProblemTest : public ::testing::Test {
 public:
  virtual void SetUp() {}

 protected:
  std::unique_ptr<DistanceApproachProblem> distance_approach_ = nullptr;
  int num_of_variables_ = 160;
  int num_of_constraints_ = 200;
  std::size_t horizon_ = 20;
  float ts_ = 0.01;
  Eigen::MatrixXd ego_ = Eigen::MatrixXd::Ones(4, 1);
  Eigen::MatrixXd x0_ = Eigen::MatrixXd::Ones(4, 1);
  Eigen::MatrixXd xf_ = Eigen::MatrixXd::Ones(4, 1);
  Eigen::MatrixXd XYbounds_ = Eigen::MatrixXd::Ones(4, 1);
  Eigen::MatrixXd vOb_ = Eigen::MatrixXd::Ones(12, 4);
  std::size_t nOb_ = 10;
};

TEST_F(DistanceApproachIPOPTInterfaceTest, initilization) {
  distance_approach_.reset(new DistanceApproachProblem(
      x0_, xf_, horizon_, ts_, ego_, xWS, uWS, timeWS, XYbounds, obstacles_num,
      obstacles_vertices_num, obstacles_A, obstacles_b));
  EXPECT_NE(ptop_, nullptr);
}

}  // namespace planning
}  // namespace apollo