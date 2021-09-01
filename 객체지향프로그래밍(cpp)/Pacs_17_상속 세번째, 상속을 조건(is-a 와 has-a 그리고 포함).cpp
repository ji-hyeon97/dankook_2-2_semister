/*
is-a 관계 : 상속에 있어서 우리느 주로 public 상속에 대해서 이야기 할 것이고, 사용할 것이다. 그럼 우리가 주로
사용할 public 상속을 사용할때는 is-a관계가 성립되도록 만들어야 한다. 그럼 is-a 관계는 무슨 관계인가?
말 그대로 is a : ~은 ~이다 라는 관계를 성립하자는 이야기 이다.
예를들어 사람과 학생의 관계를 생각해 보자(Person - Student)
-> Person is a student : 사람은 학생이다. 이것은 성립이 안된다. 모든 사람이 학생일수는 없기 떄문이다.
-> Student is a person : 학생은 사람이다. 이것은 성립된다. 그래서 우리가 상속 클래스를 만들때, Student 클래스는 파생클래스로
Person 클래스를 상속할 수 있는 것이다.
* 왜 is-a 관계여야 하냐?
위와 같은 상속 관계에서 클래스는 모든 사람의 공통적인 분모를 가지고 추상화 시켜서 클래스를 만들 것이다. 각각의 클래스의 범위는
모든 사람, 모든 학생, 모든 장학생으로 범위가 잡혀질 것이다. 일반적으로 사람이 10명 있을 때보다, 5명 있을때(즉 인원수가 적을수록)
우리는 더 많은 공통적인 특성을 더 많이 뽑을 수 있다.
위의 그림을 보면, 아래로 내려 갈수록 범위는 좁아지겠지만, 기능은 더 많아질 것이다. 범위가 좁아지기 위해서는 is-a 관계로 형성
되어야 한다. 기능이 많아지면 멤버 함수가 늘어 난다는 의미인데 그것이 c++의 상속적 특성과 완전히 일치한다. 그래서 is-a 관계를
성립시키는 것이 상속을 하는 조건에 있어서 반드시 필요하다.

상속관계에 있을 때, 아래로 갈수록 구체화 또는 특수화 되어지고, 올라갈수록 보다 일반화 되어 진다.
정리 하자며느 is-a 관계가 성립될 때, 아래로 갈수록 특성이 많아 지는데 이러한 특성을은 멤버 함수와 멤버 변수로서 반영이 되고,
그렇기 때문에 상속으로서 관계를 맺어 줄 수 있는 것이다. 상속 관계에 있을 떄 파생클래스는 기본클래스의 모든 특성들을 포함하기
때문에(특성이 많아 지기 때문에) is-a 관계로 표현 한다.

is-a 관계의 잘못된 상속 예
아까 위에서 성립이 안된다던 Person is a student의 is-a 관계를 예로 한번 들어 보자. 만약 Student 클래스에서 공부하는 기능인 
study함수가 있고 Person 클래스가 Student 클래스를 상속 했다고 하자. main 에서 Person객체를 여러개 생성했다고 하면 Person은 
상속받은 함수의 기능을 가지고 있으므로, 모두 study기능을 가지고 있을 것이다. 하지만, 모든 사람이 공부를 하는 것을 하닐 것이다.
그럼에도 불구하고 스터디 기능을 다 가지고 있을 것이다. 왜냐하면 우리가 프로그래밍에서 상속관계를 이렇게 묶어 냈기 때문이다. 
그래서 문제가 된다. 프로그램도 현실세계에 있는 기능을 그대로 프로그래밍 언어로 표현한 것이기 때문에 현실세계와 동떨어 지면 
그 프로그램은 난해한 프로그램이 되는 것이다. 따라서 is-a 관계를 성립 되도록 만들어야 한다.

Has-a 관계
is-a 관계와 마찬가지로 ~has a ~ : ~가 ~을 소유한다. 이런 의미를 가지는 관계를 말한다. 예를 들어 보면 이런것이다.
Policeman have a cudfel : 경찰은 몽둥이를 소유한다.

#include<iostream>
using namespace std;

class Cudgel {
public:
	void Swing(){
		cout << "Swing a cudgel!" << endl;
	}
};

class Police : public Cudgel {
public:
	void UseWeapon() {
		Swing();
	}
};

int main() {
	Police pol;
	pol.UseWeapon();
	return 0;
}
위에서 몽둥이 클래스는 휘두르는 기능인 Swing 함수를 가지고 있다. 경찰 클래스는 몽둥이 클래스를 상속했기에 몽둥이 클래스의 기능을
사용할 수 있다.(즉, 소유한 것이다.) 이것으로 "Police is cudgel"의 is-a 관계는 성립이 안되지만, has-a관계가 성립 되어도
상속이 된다는 것을 알 수 있다.

Has -a 관계에의한 상속 & 포함
: has -a 관계는 상속 뿐만 아니라, 다른 방법에 의해서도 표현가능하다. 그것이 바로 포함이라는 개념이다. 그 첫번째는 객체 멤버에 의한
포함관계" 이다.

#include<iostream>
using namespace std;

class Cudgel {
public:
	void Swing() {
		cout << "Swing a cudgel!" << endl;
	} 
};

class Police {
	Cudgel cud;
public:
	void UseWeapon() {
		cud.Swing();
	}
};

int main() {
	Police pol;
	pol.UseWeapon();

	return 0;
}
Police Class의 멤버 변수로 Cudgel class의 객체가 왔다.(C에서의 구조체 멤버로 구조체 변수가 올 수 있는 것과
같은 이치) C++은 기본 자료형이나 사용자 정의 자료형이나 동일시 하고 있는 특성을 가지고 있다.
그러기에 이런 선언이 가능한 것이다.
일단 메인 함수에서 클래스의 객체로 만들때 어떻게 만들어 지는지 알아 보자
처음에 pol이라는 이름으로 메모리 공간을 할당하고 cudgel 객체를 위한 메모리 공간도 할당을 해 줄 것이다.
이때의 순서를 정하자면 Police 메모리 공간 할당 -> cudgel 객체 메모리 공간할당&생성자 호출 -> Police생성자 호출이 이루어 질것이다.
75번째 줄인 Cudgel cud;는 명시적으로 어떤 생성자를 호출 하라고 명시 되어 있지 않으므로, Cudgel 클래스의 인자값을 받지 않는
void 생성자를 호출 할 것이다. 이러한 형태로 클래스의 객체가 멤버로 포함되기 위해서는 반드시 인자값 받지 않는 void 생성자를 지녀야
한다. 여기서 75번째 줄에 Cudgel cud(10); 이라는 문장도 쓸 수 있지 않을까? 라는 의구심을 가지게 된다. "cud 생성과정에서 10이라는 
인자값을 받는 생성자를 호출 하겠다" 라는 의미이다. 이런 문장이 올 수 있을 거 같지만, 못온다. 이 문장은 객체를 생성과 동시에
초기화라는 효과를 가지는데 C에서 구조체 멤버변수 선언과 동시에 초기화 불가능한 것과 마찬가지로 C++에서도 클래스의 멤버는 생성과
동시에 초기화가 불가능 하다. 따라서 C++은 클래스의 객체가 멤버로 존재하기 위해서는 그 객체를 기반으로 하는 클래스는 반드시 void
생성자를 지녀야 한다.
결과적으로 생성된 police 객체에는 cud라는 객체가 존재하는 것이다. police는 cud를 포함하고 있는 것이다. 그렇기 때문에 UseWeapon 함수를
호출하면서, 자기가 가지고 있는 Swing 함수를 호출 할 수 있는 것이다. 이를 포함관계라고 하고, UML에서는 아래와 같이 표현한다.

객체 포인터 멤버에 의한 포함관계
*/
#include<iostream>
using namespace std;

class Cudgel { //몽둥이
public:
	void Swing() {
		cout << "Swing a cudgel ! " << endl;
	}
};

class Police { //몽둥이를 소유한 경찰
	Cudgel *cud;
public:
	Police() {
		cud = new Cudgel; //객체 동적 생성(void 생성자 호출) 인자값 받는 객체 동적 생성도 가능
	}
	~Police() {
		delete cud;
	}
	void UseWeapon(){
		cud->Swing();
	}
};

int main() {
	Police pol;
	pol.UseWeapon();

	return 0;
}
/*
예제는, 객체 포인터 멤버에 의한 포함관계의 예제이다. 일단 그림을 한번 보자.
117번째 줄에서, cudgel 객체가 생성되고, 그 포인터를 cud라는 멤버에 대입을 하니까 police 객체는 cud 객체를 위와 같이
가르키는 형태를 띄게 될 것이다. 그렇기 때문에, UseWeapon 함수에서는 cud라는 포인터가 가르키는 객체의 swing함수를 호출할 수 있다.
객체는 동적 생성했으므로, cudgel 객체는 힙에 있을 것이고 메인함수에서 생성된 지역적인 특성을 지니는 객체이므로 cud는 스택에 
존재할 것이다. 논리적으로 Police클래스 Cudgel 객체의 포인터를 가지고 있으므로 그것을 소유 하고 있는 것이다(언제든지 참조 가능).
이것도 역시 포함 관계에 해당된다. 위의 형태를 가진 것이 바로 객체 포인터 멤버에 의한 포함관계 이다.(주로 이것을 많이 쓴다.)

상속을 묶인 두 개의 클래스는 강한 연관성을 띄게 된다. 만약 소유관계의 상속에서 경찰이 몽둥이를 가지지 않는 경찰을 표현하기 위해서는 클래스의
구조 자체를 바뀌어야 한다. 하지만 이를 포함관계로 구성하면 간단히 표현이 가능해 진다. 따라서 상속은 is-a 관계의 표현에 매우 적절하다.
그리고 경우에 따라서는 Has-A 관계의 표형에도 사용될수 있으나 이는 츠로그램의 변경에 많을 제약을 가져다 줄 수 있다.
*/