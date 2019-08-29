#pragma once

#include "layer.h"

class Screen;

class PickerLayer : public Layer {
public:
	PickerLayer();
	PickerLayer(Screen* screen, char flags = none);

	void init() override;
	void update() override;
	void render() override;
	void close() override;
};