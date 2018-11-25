#pragma once

#include <chrono>
#include <thread>

#include "../util/Log.h"

using namespace std::chrono;

class TickerThread {
private:
	std::thread thread;
	bool stopped = false;
	double TPS;
	milliseconds tickSkipTimeout;
	void(*tickAction)();
public:
	TickerThread() : thread() {};
	TickerThread(double targetTPS, milliseconds tickSkipTimeout, void(*tickAction)());
	~TickerThread();

	TickerThread& operator=(TickerThread&& rhs) {
		this->thread = std::thread();
		this->stopped = rhs.stopped;
		this->TPS = rhs.TPS;
		this->tickSkipTimeout = rhs.tickSkipTimeout;
		this->tickAction = rhs.tickAction;

		return *this;
	}

	TickerThread& operator=(const TickerThread&) = delete;

	void start();
	void stop();

	void setTPS(double newTPS) {this->TPS = newTPS;}
	double getTPS() const { return this->TPS; }
};