#include <iostream>
#include <algorithm>
#include<vector>
#include<set>
#include<ranges>
#include<algorithm>
#include <chrono>

#include "src/SKELConverter/ConversionPipeline/CPipeline.h"
using std::vector;
using std::set;
using std::greater;
using namespace std;
using namespace ConversionPipeline;

/*BodyProcessor<float, vector<vector<float>>> processor = BodyProcessor<float, vector<vector<float>>>();*/
set<float> coordSet = set<float>();


/* Body Processor Tests*/
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



    /*int coordIndexes = GENERATE(0, 1, 2);
    REQUIRE(coordQuantity(coordIndexes, objData) == true);
    REQUIRE(checkTopFace(vertices));
    REQUIRE(checkBottomFace(vertices));*/




/* Pipeline Tests*/
    /* Components */

    void linkComponents(vector<PipelineComponent*> components){
        for (int i = 0 ; i < components.size() - 1; i++) {
            PipelineComponent* nextComponent = components[i + 1];
            components[i]->joinOutput(nextComponent);
        }
        for (int i = 0 ; i < components.size(); i++) {
            if (components[i]->output == nullptr) {
                std::cout << "Not linked!!!" << std::endl;
            }else {
                std::cout << "Linked successfully" << std::endl;
            }
        }

    }

    void componentsMessagePassing(vector<PipelineComponent*> &components) {
        Message* testMessage = new Message();
        std::unique_ptr<Message> messagePtr(testMessage);
        components[0]->setState(std::move(messagePtr));
        for (int i = 0 ; i < components.size(); i++) {
            std::cout << components[i]->getState() << std::endl;
            if (components[i]->output != nullptr) {
                std::cout << "connected" << std::endl;
            }
            components[i]->releaseState();
        }

    }
    /*Listeners and Validators*/

    void linkPubAndSub(Validator* validator, ConcreteValidatorListener* listener) {
        validator->setListener(listener);
    }
    void messageFunctionalityTest(Validator* validator, ConcreteValidatorListener* listener) {
        linkPubAndSub(validator, listener);
        ValidatorStatusMessage* testMessage = new ValidatorStatusMessage();
        std::unique_ptr<ValidatorStatusMessage> messagePtr(testMessage);
        validator->setState(std::move(messagePtr));
        validator->notifyListener(std::move(validator->getState()));
        std::cout << validator->getState() << std::endl;
        std::cout << listener->message << std::endl;
        validator->flush();
        std::cout << listener->passMessage() << std::endl;
    }

    /* Orchestrator */

    void trackerCreationTest(PipelineOrchestrator* orchestrator) {
        orchestrator->makeTracker("1234");
    }
    void trackerUpdateTest(PipelineOrchestrator* orchestrator) {
        trackerCreationTest(orchestrator);
        Message* testMessage = new Message();
        testMessage->metadata["trackerID"] = "1234";
        testMessage->metadata["affectedBody"] = "shoulderB";
        testMessage->metadata["process"] = "romCalculator";

        orchestrator->updateTracker(testMessage);
    }



int main() {

   PipelineComponent comp1 = PipelineComponent();
    PipelineComponent* ptr1 = &comp1;
   PipelineComponent comp2 = PipelineComponent();
    PipelineComponent* ptr2 = &comp2;
    PipelineComponent comp3 = PipelineComponent();
    PipelineComponent* ptr3 = &comp3;
    PipelineComponent comp4 = PipelineComponent();
    PipelineComponent* ptr4 = &comp4;

    auto components = vector{
        ptr1,
        ptr2,
        ptr3,
        ptr4
    };

    linkComponents(components);
    componentsMessagePassing(components);

    Validator* validator = new Validator();
    ConcreteValidatorListener* listener = new ConcreteValidatorListener();
    messageFunctionalityTest(validator, listener);

    PipelineOrchestrator* orchestrator = new PipelineOrchestrator();
    trackerUpdateTest(orchestrator);



    auto pipeline = CPipeline();
    pipeline.buildPipeline();
    /*
    vector<vector<float>> objData = {{1.2, 5.6, 4.5}, {7.8, 3.4, 6.7}};
    processor.sortVertices(objData);

    vector<vector<float>> vertices = processor.findTorso();
    */

    return 0;
}