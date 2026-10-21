#include <iostream>
#include <memory>
#include <string>
#include "Vehicle.h"
#include "VehicleFactory.h"
#include <windows.h>
enum class ParseResult { Ok, NotANumber, NotPositive };
void printMenu() {
    std::cout << "\n=== Вибір транспортного засобу ===\n"
        << "1 - Car (легковий автомобіль)\n"
        << "2 - Truck (вантажівка)\n"
        << "3 - Bus (автобус)\n"
        << "Введіть номер: ";
}
// Перевіряє, чи введене значення є числом і чи воно додатне
ParseResult parseChoice(const std::string& text, int& value) {
    try {
        std::size_t pos = 0;
        long long number = std::stoll(text, &pos);
        if (text.find_first_not_of(" \t", pos) != std::string::npos) {
            return ParseResult::NotANumber;  // наприклад "2abc"
        }
        if (number <= 0) return ParseResult::NotPositive;
        if (number > 1000000) number = 1000000;  // дуже велике число або не існує
        value = static_cast<int>(number);
        return ParseResult::Ok;
    }
    catch (const std::exception&) {  // invalid_argument
        return ParseResult::NotANumber;
    }
}

int main() {
	SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    while (true) {
        printMenu();
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cout << "\nВвід завершено. До побачення!\n";
            return 0;
        }
        int choice = 0;
        ParseResult parsed = parseChoice(line, choice);
        if (parsed == ParseResult::NotANumber) {
            std::cout << "Помилка: потрібно ввести число, а не текст.\n";
            continue;
        }
        if (parsed == ParseResult::NotPositive) {
            std::cout << "Помилка: число має бути додатним (0 і від'ємні значення не підходять).\n";
            continue;
        }
        // Об'єкт створює фабрика, а не main().
        std::unique_ptr<Vehicle> vehicle = VehicleFactory::create(choice);
        if (!vehicle) {
            std::cout << "Помилка: транспорту з номером " << choice
                << " не існує. Оберіть 1, 2 або 3.\n";
            continue;
        }
        std::cout << "\nСтворено: " << vehicle->getName() << "\n"
            << "Максимальна швидкість: " << vehicle->getMaxSpeed() << " км/год\n";
        vehicle->drive();
        std::cout << "\nСтворити ще один транспорт? (1 - так, інше - вихід): ";
        std::string again;
        if (!std::getline(std::cin, again) || again != "1") {
            std::cout << "До побачення!\n";
            return 0;
        }
    }
}