#pragma once

#include "entities/Vago.h"
#include "entities/Cucaracha.h"
#include "entities/Maleta.h"
#include "entities/Libro1.h"
#include "entities/Rail.h"

class Level {
public:
	static void buildFirstLevel(GLuint sh_programID);
	Vago* my_vago;
	Cucaracha* cucaracha;
	Maleta* maleta;
	Libro1* libro1;
	Rail* rail;
	Rail* padlock;

	//llums
	bool* llumAmbient;
	bool* iFixe;

	InteractableEntity* my_entity_under_cursor;

	static Level CURRENT_LEVEL;


	void MaybeSpawnSlender();
	void despawnSlender();
};