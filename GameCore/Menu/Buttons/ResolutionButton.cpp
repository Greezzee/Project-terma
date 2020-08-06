#include "ResolutionButton.h"

#include <cstdio>
#include <iostream>

ResolutionButton::ResolutionButton() {
}

void ResolutionButton::clickReact() {
	// Nothing for now
}

void ResolutionButton::focusReact() {
	// Nothing for now
}

void ResolutionButton::disfocusReact() {
	// Nothing for now
}

void ResolutionButton::Destroy() {
	printf("ResolutionButton destroyed!\n");
	std::cout.flush();
}

void ResolutionButton::Init(GameObject *owner) {
	printf("ResolutionButton created!\n");
	std::cout.flush();
}
