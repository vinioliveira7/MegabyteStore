//
// Created by Vinicius on 27/10/2022.
//

#include "CPU.h"
namespace Models {
    CPU::CPU(string socket, int cores, int threads, double basicClock, double boostMaximumClock, string brand, string model, int id, int quantity, double value) : Hardware(brand, model, id, quantity, value, CPUTYPE), Socket(socket) {
        setSocket(socket);
        setCores(cores);
        setThreads(threads);
        setBasicClock(basicClock);
        setBoostMaximumClock(boostMaximumClock);
    }

    string CPU::getSocket() {
        return socket;
    }

    void CPU::setSocket(string newSocket) {
        socket = newSocket;
    }

    int CPU::getCores() {
        return cores;
    }

    void CPU::setCores(int newCores) {
        cores = newCores;
    }

    int CPU::getThreads() {
        return threads;
    }

    void CPU::setThreads(int newThreads) {
        threads = newThreads;
    }

    double CPU::getBasicClock() {
        return basicClock;
    }

    void CPU::setBasicClock(double newBasicClock) {
        basicClock = newBasicClock;
    }

    double CPU::getBoostMaximumClock() {
        return boostMaximumClock;
    }

    void CPU::setBoostMaximumClock(double newBoostMaximumClock) {
        boostMaximumClock = newBoostMaximumClock;
    }


    void CPU::View() {
        cout << "ID: " << id << endl;
        cout << "Quantidade: " << quantity << endl;
        cout << "Valor: " << value << endl;
        cout << "Marca: " << brand << endl;
        cout << "Modelo: " << model << endl;
        cout << "Socket: " << type << endl;
        cout << "Nucleos: " << cores << endl;
        cout << "Threads: " << threads << endl;
        cout << "Clock basico: " << basicClock << endl;
        cout << "Clock maximo com boost: " << boostMaximumClock << endl;

    }

    json CPU::ToJson() {
        json jsonCpu;
        jsonCpu = {
                { "id", id },
                {"quantity", quantity},
                {"value", value},
                {"brand", brand},
                {"model", model},
                {"socket", socket},
                {"cores", cores},
                {"threads", threads},
                {"basic_clock", basicClock},
                {"boost_clock", boostMaximumClock}
        };
        return jsonCpu;
    }

    CPU* CPU::FromJson(json jsonObject) {
        CPU* cpu = new CPU(jsonObject["socket"],
                           jsonObject["cores"],
                           jsonObject["threads"],
                           jsonObject["basic_clock"],
                           jsonObject["boost_clock"],
                           jsonObject["brand"],
                           jsonObject["model"],
                           jsonObject["id"],
                           jsonObject["quantity"],
                           jsonObject["value"]);

        return cpu;
    }
}