#include <algorithm>
#include "../../../src/SKELConverter/ConversionPipeline/PipelineComponents/Processors/BodyProcessor/BodyProcessor.h"
#include<vector>
#include<catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include<set>
#include<ranges>
#include<algorithm>
using std::vector;
using std::set;
using std::greater;
using ConversionPipeline::BodyProcessor;


BodyProcessor<float, vector<vector<float>>> processor = BodyProcessor<float, vector<vector<float>>>();
set<float> coordSet = set<float>();

bool coordQuantity(int coord, vector<vector<float>> vertices) {
    coordSet.clear();
    for (vector<float> points: vertices) {
        coordSet.insert(points[coord]);
    }
    return coordSet.size() == 2;
}
bool compareDimensions(std::span<vector<float>> data) {
    float width = 0;
    float length = 0;
    for (int i = 0; i < data.size(); i++) {
        for (int j = i + 1; j < data.size(); j++) {
            if (data[i][1] == data[j][1]) {
                float greaterVal = data[i][0] > data[j][0] ? data[i][0] : data[j][0];
                float lesserVal = data[i][0] < data[j][0] ? data[i][0] : data[j][0];
                if (width != 0) {
                    if (greaterVal - lesserVal != width) {
                        return false;
                    }
                }else {
                    width = greaterVal - lesserVal;
                }
            }
            if (data[i][0] == data[j][0]) {
                float greaterVal = data[i][1] > data[j][1] ? data[i][1] : data[j][1];
                float lesserVal = data[i][1] < data[j][1] ? data[i][1] : data[j][1];
                if (length != 0) {
                    if (greaterVal - lesserVal != length) {
                        return false;
                    }
                }else {
                    length = greaterVal - lesserVal;
                }
            }
        }
    }
    return true;
}

bool checkTopFace(vector<vector<float>> data) {
    vector<vector<float>> topFaceVertices = data;
    std::ranges::sort(topFaceVertices, greater{}, [](const auto& row){return row[2];});
    std::span<vector<float>> topFaceVerticesSpan = std::span(topFaceVertices.begin(), topFaceVertices.end() +
        std::ranges::count_if(topFaceVertices.begin(), topFaceVertices.end(), [topFaceVertices](const auto& row) {
            return row[2] < topFaceVertices.front()[2];
        }));
    if (topFaceVerticesSpan.size() != data.size() / 2) {
        return false;
    }

    return false ? !compareDimensions(topFaceVerticesSpan) : true;
}

bool checkBottomFace(vector<vector<float>> data) {
    vector<vector<float>> bottomFaceVertices = data;
    std::ranges::sort(bottomFaceVertices, [](auto const &x, auto const &y){return x[2] < y[2];});
    std::span<vector<float>> bottomFaceVerticesSpan = std::span(bottomFaceVertices.begin(), bottomFaceVertices.end() +
        std::ranges::count_if(bottomFaceVertices.begin(), bottomFaceVertices.end(), [bottomFaceVertices](const auto& row) {
            return row[2] > bottomFaceVertices.front()[2];
        }));
    if (bottomFaceVerticesSpan.size() != data.size() / 2) {
        return false;
    }

    return false ? !compareDimensions(bottomFaceVerticesSpan) : true;

}


TEST_CASE("BodyProcessors", "findTorso") {
    vector<vector<float>> objData = {};
    vector<vector<float>> vertices = processor.findTorso(objData);
    REQUIRE(vertices.size() == 8);
    int coordIndexes = GENERATE(0, 1, 2);
    REQUIRE(coordQuantity(coordIndexes, objData) == true);
    REQUIRE(checkTopFace(vertices));
    REQUIRE(checkBottomFace(vertices));



}


int main() {
    return 0;
}