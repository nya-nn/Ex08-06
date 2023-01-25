#include <iostream>
#include<stdio.h>
using namespace std;
#define _USE_MATH_DEFINES
#include <math.h>

class Solid {
public:
	virtual double GetVolume() = 0;
	virtual double GetSurface() = 0;
};

class Box :public Solid {
private:
	double width;
	double height;
	double depth;
	void SetWidth(double w) {
		this->width = w;
	}
	void SetHeight(double h) {
		this->height = h;
	}
	void SetDepth(double d) {
		this->depth = d;
	}
public:
	Box(double width, double height, double depth) {
		SetWidth(width);
		SetHeight(height);
		SetDepth(depth);
	}
	double GetWidth() {
		return width;
	}
	double GetHeight() {
		return height;
	}
	double GetDepth() {
		return depth;
	}
	double GetVolume() {
		return width * height * depth;
	}
	double GetSurface() {
		return (width * height) * 2 + (width * depth) * 2 + (height * depth) * 2;
	}
};

class Cylinder :public Solid {
private:
	double radius;
	double height;
	void SetRadius(double r) {
		this->radius = r;
	}
	void SetHeight(double h) {
		this->height = h;
	}

public:
	Cylinder(double radius, double height) {
		SetRadius(radius);
		SetHeight(height);
	}
	double GetRadius() {
		return radius;
	}
	double GetHeight() {
		return height;
	}
	double GetVolume() {
		return (M_PI * radius * radius) * height;
	}
	double GetSurface() {
		return (M_PI * radius * radius) * 2 + (M_PI * radius * 2) * height;
	}
};

class Cone :public Solid {
private:
	double radius;
	double height;
	void SetRadius(double r) {
		this->radius = r;
	}
	void SetHeight(double h) {
		this->height = h;
	}

public:
	Cone(double radius, double height) {
		SetRadius(radius);
		SetHeight(height);
	}
	double GetRadius() {
		return radius;
	}
	double GetHeight() {
		return height;
	}
	double GetVolume() {
		return (M_PI * radius * radius * height) / 3;
	}
	double GetSurface() {
		double busbar = (radius * radius) + (height * height) * sqrt(2);
		return (M_PI * radius * (busbar + radius));
	}
};

class Sphere :public Solid {
private:
	double radius;
	void SetRadius(double r) {
		this->radius = r;
	}

public:
	Sphere(double radius) {
		SetRadius(radius);
	}
	double GetRadius() {
		return radius;
	}
	double GetVolume() {
		return (double)4 / (double)3 * (M_PI * radius * radius * radius);
	}
	double GetSurface() {
		return (double)4 * (M_PI * radius * radius);
	}
};

class Package {
private:
	double width;
	double height;
	double depth;
	double size;

	void SetWidth(double w) {
		this->width = w;
	}
	void SetHeight(double h) {
		this->height = h;
	}
	void SetDepth(double d) {
		this->depth = d;
	}
public:
	char guidance[];
	Package(double w, double h, double d) {
		SetWidth(w);
		SetHeight(h);
		SetDepth(d);
	}

	void GetSize() {
		int cardboard=0;
		size = width + height + depth;
		if (size <= 60) {
			cardboard = 60;
		}
		else if (size <= 80) {
			cardboard = 80;
		}
		else if (size <= 100) {
			cardboard = 100;
		}
		else if (size <= 120) {
			cardboard = 120;
		}
		else if (size <= 140) {
			cardboard = 140;
		}
		else if (size <= 160) {
			cardboard = 160;
		}
		else if (size <= 170) {
			cardboard = 170;
		}
		else if (size <= 180) {
			cardboard = 180;
		}
		else if (size <= 200) {
			cardboard = 200;
		}

		if (cardboard <= 160) {
			sprintf_s(guidance, 16, "宅急便、ゆうパック共に%dサイズ", cardboard);
			printf("%s", guidance);
		}
		else if (cardboard == 170) {
			cout << "宅急便は180サイズ、ゆうパックは170サイズ";
		}
		else if (cardboard <= 200) {
			sprintf_s(guidance,16, "宅急便は%dサイズ、ゆうパックでは送れません", cardboard);
			printf("%s", guidance);
		}
		else {
			cout << "宅急便、ゆうパックでは送れません";
		}
	}
};
int main()
{
	double width;
	double height;
	double depth;
	double radius;

	cout << "箱の幅を入力:";
	cin >> width;
	cout << "箱の高さを入力:";
	cin >> height;
	cout << "箱の奥行きを入力:";
	cin >> depth;

	Box* box = new Box(width, height, depth);
	Package* package = new Package(width, height, depth);
	cout << "箱の体積は" << box->GetVolume() << endl;
	cout << "箱の面積は" << box->GetSurface() << endl;
	package->GetSize();

	cout <<endl<< "円柱の半径を入力:";
	cin >> radius;
	cout << "円柱の高さを入力:";
	cin >> height;

	Cylinder* cylinder = new Cylinder(radius, height);
	Package* package2 = new Package(radius * 2, height, radius * 2);
	cout << "円柱の体積は" << cylinder->GetVolume() << endl;
	cout << "円柱の面積は" << cylinder->GetSurface() << endl;
	package2->GetSize();

	cout <<endl<< "円錐の半径を入力:";
	cin >> radius;
	cout << "円錐の高さを入力:";
	cin >> height;

	Cone* cone = new Cone(radius, height);
	Package* package3 = new Package(radius * 2, height, radius * 2);
	cout << "円錐の体積は" << cone->GetVolume() << endl;
	cout << "円錐の面積は" << cone->GetSurface() << endl;
	package3->GetSize();

	cout <<endl<< "球の半径を入力:";
	cin >> radius;

	Sphere* sphere = new Sphere(radius);
	Package* package4 = new Package(radius * 2, radius * 2,radius*2);
	cout << "球の体積は" << cone->GetVolume() << endl;
	cout << "球の面積は" << cone->GetSurface() << endl;
	package4->GetSize();

}