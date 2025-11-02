//
// Created by teddy on 22/09/2025.
//

#ifndef MESSAGE_H
#define MESSAGE_H
#include <ctime>
#include <map>
#include <string>
#include <vector>
using std::vector;
using std::string;
namespace ConversionPipeline {
class Message {
public:
    Message();
    time_t creationTime;
    std::string id;
    vector<vector<float>> contents;
    std::map<std::string, std::string> metadata;
};

} // ConversionPipeline

#endif //MESSAGE_H
