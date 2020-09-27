#pragma once

#include "ecs/material.h"
#include "../engine/visualData.h"
#include "../graphics/visualShape.h"
#include "../physics/part.h"
#include "../engine/ecs/registry.h"

namespace P3D::Application {

struct ExtendedPart : public Part {
	using Entity = typename Engine::Registry64::entity_type;

	Material material;

	std::string name;

	int renderMode = 0x1B02; // GL_FILL

	VisualData visualData;

	// Transition
	Entity entity;
	ExtendedPart(Part&& part, Entity entity/* = 0*/); 
	ExtendedPart(const Shape& hitbox, const GlobalCFrame& position, const PartProperties& properties, Entity entity/* = 0*/);
	ExtendedPart(const Shape& hitbox, ExtendedPart* attachTo, const CFrame& attach, const PartProperties& properties, Entity entity/* = 0*/);

	ExtendedPart() = default;
	ExtendedPart(Part&& part, std::string name = "Part");
	ExtendedPart(Part&& part, VisualData visualData, std::string name = "Part");
	ExtendedPart(const Shape& hitbox, const GlobalCFrame& position, const PartProperties& properties, std::string name = "Part");
	ExtendedPart(const Shape& hitbox, const GlobalCFrame& position, const PartProperties& properties, VisualData visualData, std::string name = "Part");
	ExtendedPart(const Shape& hitbox, ExtendedPart* attachTo, const CFrame& attach, const PartProperties& properties, std::string name = "Part");
};

};