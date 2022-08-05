#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h>
using namespace std;

#define SIZE_X 80
#define SIZE_Y 24

#define RESET "\e[0m"
#define BOLD "\e[1m"
#define DIM "\e[2m"
#define UNDERLINE "\e[4m"
#define BLINK "\e[5m"
#define INVERTED "\e[7m"
#define HIDDEN "\e[8m"

#define RESET_COLOR "\e[39m"
#define BLACK "\e[30m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define MAGENTA "\e[35m"
#define CYAN "\e[36m"
#define LIGHT_GRAY "\e[37m"
#define DARK_GRAY "\e[90m"
#define LIGHT_RED "\e[91m"
#define LIGHT_GREEN "\e[92m"
#define LIGHT_YELLOW "\e[93m"
#define LIGHT_BLUE "\e[94m"
#define LIGHT_MAGENTA "\e[95mLight magenta"
#define LIGHT_CYAN "\e[96m"
#define WHITE "\e[97m"

#define BG_RESET_COLOR "\e[49m"
#define BG_BLACK "\e[40m"
#define BG_RED "\e[41m"
#define BG_GREEN "\e[42m"
#define BG_YELLOW "\e[43m"
#define BG_BLUE "\e[44m"
#define BG_MAGENTA "\e[45m"
#define BG_CYAN "\e[46m"
#define BG_LIGHT_GRAY "\e[47m"
#define BG_DARK_GRAY "\e[100m"
#define BG_LIGHT_RED "\e[101m"
#define BG_LIGHT_GREEN "\e[102m"
#define BG_LIGHT_YELLOW "\e[103m"
#define BG_LIGHT_BLUE "\e[104m"
#define BG_LIGHT_MAGENTA "\e[105m"
#define BG_LIGHT_CYAN "\e[106m"
#define BG_WHITE "\e[107m"

class Printer {
	vector<vector<char>> screen;
	vector<vector<string>> styles;
public:
	Printer();

	void put_symbol(int x, int y, char symbol);
	void set_style(int x, int y, string style);
	string construct_color(int code);
	void draw();
};

Printer::Printer() {
	screen = vector<vector<char>>(SIZE_Y, vector<char>(SIZE_X, ' '));
	styles = vector<vector<string>>(SIZE_Y, vector<string>(SIZE_X, RESET));
	cout << endl;
}

void Printer::put_symbol(int x, int y, char symbol) {
	screen[y + 1][x + 1] = symbol;
}

void Printer::set_style(int x, int y, string style) {
	styles[y + 1][x + 1] = style;
}

string construct_color(int code) {
	return (string) "\e[38;5;" + code + (string) "m";
}

string construct_bg_color(int code) {
	return (string) "\e[48;5;" + code + (string) "m";
}

void Printer::draw() {
	for (int y = 0; y < SIZE_Y; y++) {
		cout << screen[y][0];
		for (int x = 1; x < SIZE_X; x++) {
			if (styles[y][x - 1] != styles[y][x]) {
				cout << styles[y][x];
			}
			cout << screen[y][x];
		}
		cout << endl;
	}
}

int main() {
	Printer printer;
	while (true) {
		printer.put_symbol(5, 5, '#');
		printer.set_style(5, 5, RED BOLD UNDERLINE BG_LIGHT_MAGENTA);
		printer.put_symbol(7, 5, '#');
		printer.put_symbol(5, 8, '#');
		printer.put_symbol(6, 8, '#');
		printer.put_symbol(7, 8, '#');
		printer.draw();
		usleep(50000);
	}
	return 0;
}
