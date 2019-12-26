#include "backend/vertex.h"
#include <iostream>

namespace myslam {
namespace backend {

unsigned long global_vertex_id = 0;

Vertex::Vertex(int num_dimension, int local_dimension) {// local_dimension 本地参数化维度，为-1时认为与本身维度一样
    parameters_.resize(num_dimension, 1);
    local_dimension_ = local_dimension > 0 ? local_dimension : num_dimension;
    id_ = global_vertex_id++;// 顶点的id，自动生成

//    std::cout << "Vertex construct num_dimension: " << num_dimension
//              << " local_dimension: " << local_dimension << " id_: " << id_ << std::endl;
}

Vertex::~Vertex() {}

int Vertex::Dimension() const {
    return parameters_.rows();
}

int Vertex::LocalDimension() const {
    return local_dimension_;
}

void Vertex::Plus(const VecX &delta) {
    parameters_ += delta;
}

}
}