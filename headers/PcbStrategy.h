//
// Created by Beaver on 05/01/2024.
//

#pragma once
#include <string>

class PCBStrategy {
public:
    virtual void produce(const std::string& size, const std::string& color) = 0;
};

class SmallPCB : public PCBStrategy {
public:
    void produce(const std::string& size, const std::string& color) override;
};

class MediumPCB : public PCBStrategy {
public:
    void produce(const std::string& size, const std::string& color) override;
};

class LargePCB : public PCBStrategy {
public:
    void produce(const std::string& size, const std::string& color) override;
};

class PCBFactory {
private:
    PCBStrategy* pcbStrategy;

public:
    void setPCBStrategy(PCBStrategy* strategy);
    void manufacture(const std::string& size, const std::string& color);
};


