#pragma once
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../Utility/Coordinate.h"

//! Содержит названия виртуальных клавиш.
const unsigned KeysCount = 12;
enum KeyboardKey {
	L_Left, L_Right, L_Up, L_Down, L_ShootA, L_ShootB,
	R_Left, R_Right, R_Up, R_Down, R_ShootA, R_ShootB
};

//! Временное дополнение, WIP, лучше не трогать
const unsigned PlayerKeysCount = 6;
enum PlayerKey {
	Left, Right, Up, Down, ShootA, ShootB
};

//! Хранит информацию о состоянии виртуальной клавиши
struct KeyData {
	bool is_pressed;
	bool is_realesed;
	bool is_down;
};


/*!
* Менеджер, который перехватывает данные с клавиатуры (в будущем и с мыши) и предоставляет их другим объектам в более удобном виде
* 
* Позволяет создавать настройку управления, так как хранит связь между реальными клавишами клавиатуры и виртуальными клавишами (L_Left, L_Right и тд)
* В процессе создания игры, нужно руководствоваться только виртуальными клавишами.
* Если будут появляться настройки управления, одной реальной клавише могут соответствовать разные виртуальные (но не наоборот)
* 
* Зависит от SFML
* 
* СИСТЕМНОЕ. Лезть только при добавлении новых клавиш управления
*/

struct InputManager
{
	//! НЕ ТРОГАТЬ, автоматически вызывается при инициализации игры
	static void Init();

	//! НЕ ТРОГАТЬ, автоматически вызывается каждый кадр в главном цикле
	static void Update();

	//! Вернёт true в кадр, в который виртуальная клавиша key нажимается, иначе false
	static bool IsPressed(KeyboardKey key);

	//! Вернёт true в кадр, в который виртуальная клавиша key отжимается, иначе false
	static bool IsRealesed(KeyboardKey key);

	//! Вернёт true если key нажата, иначе false
	static bool IsUp(KeyboardKey key);

	//! Вернёт true если key не нажата, иначе false
	static bool IsDown(KeyboardKey key);

private:
	static KeyData _key_info[KeysCount]; //! Массив информации о всех виртуальных клавишах
	static sf::Keyboard::Key _control_keys[KeysCount]; //! Хранит связь между реальными и виртуальными клавишами
};
