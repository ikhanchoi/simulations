
TOC: 빌드, 포인터, 클래스, 표준라이브러리, 템플릿, 멀티스레드



단골문제: 복사생성자, 이동생성자, 연산자오버로딩, 가상함수
l-value, r-value
함수 객체
스레드
TR1, 부스트



# 프로그래밍 대회 팁

## STL container
vector
	push_back, pop_back, clear, resize, size
string
	push_back, pop_back, substr
queue
	push, pop, front, empty, size
stack
	push, pop, top, empty, size

pair
	중괄호, first, second

map
 	for(auto iter:dp)
set
	for(auto iter:dp)

algorithm
	min, max
	sort(arr,arr+len)
	sort(vec.begin(),vec.end())


## 매크로
#define MAX_N 101
#define MOD 1000000007









# 0. Build
compilation
전처리
헤더 링크
build
메이크


# 1. Pointer

## 참조자

똑같은 공간에 다른 변수명을 부여하는 것

선언 시
- int* p		(int*) 타입의 변수 p를 선언
- int& b = a	b에 동의어 a를 추가
연산자로서
- * 내용물 연산자
- & 주소값 연산자

### 인자로 넘길 때

포인터 인자 함수:
- 인자가 너무 커서 복사하기 싫거나, 인자의 값을 함수 내에서 변경해야 할 때.
- 단, 함수를 호출하여 값을 넘겨줄 때 주소값 연산자 &를 붙여서 넘겨야 한다.
참조자 인자 함수:
- 인자의 값을 함수 내에서 변경해야 하나, 클래스 등이 아닌 간단한 타입의 경우.


const Object* obj; // can't change data
Object* const obj; // can't change pointer
const Object* const obj; // can't change data or pointer


## 메모리 구조
Code:  실행코드
Data:  전역변수 정적변수
Heap:  동적할당
Stack: 지역변수 매개변수

## 동적할당


## 스마트 포인터
어떤 힙영역을 가리키는 스마트포인터가 없을 경우 알아서 해제되는 기능이 있다

`shared_ptr<int>`로 정의된 포인터는 `.use_count`를 통해서 내가 가리키는 변수를 총 몇 개의 스마트포인터가 가리키고 있는지 셀 수 있다
`unique_ptr<int>`로 정의된 포인터는 다른 포인터 변수에 복사될 수 없다
카운트가 1인 shared_ptr이라 생각하면 된다
따라서 다른 포인터가 내가 가리키는 변수를 가리키지 못하게 하는 단사성이 보장된다
`weak_ptr<int>`로 정의된 포인터는 shared_ptr이 카운트하지 않는다
따라서 weak_ptr들로만 포인팅받는 변수는 그냥 해제된다
순환참조를 해결할 때 사용할 수 있다

RAII
초기화 됐을 때만 자원을 획득하자
유효하지 않은 변수는 자원 획득하지 말자
반대로 가리키는 포인터도 없고 식별자도 없어서 유효하지 않게 된 변수도 없애야 한다


## 함수포인터


void* function1(void) // declares a function which returns void*,
void (* function2)(void) // declares a function pointer to a function which returns void.




# 2. Class

## 상속

### 멤버
객체는 무엇을 소유하고 있나?
멤버변수는 소유하고 있으나 멤버함수는 소유하고 있지 않다.


### 접근한정
- 멤버들의 접근한정자

- 상속 시의 접근한정자
기본은 private인데 거의 public만 씀

- friend
외부 friend

클래스 friend

메소드 friend




## 생성자

### 기본 생성자

복사대입연산자처럼 객체가 가지는 모든 변수들을 복사

### 복사생성자
- 복사생성자의 사용
`Class(const Class& rhs){}`
참조자가 없으면 복사생성자의 무한호출이 생긴다
참조자를 붙였으니 const로 변경을 막는 것이 관례

- 깊은 복사
객체가 포인터 멤버를 가질 경우 깊은 복사와 얕은 복사의 개념이 나누어진다
기본 복사생성자는 얕은 복사를 한다
사용자정의 복사생성자로 깊은 복사를 구현해줘야 함
구체적으로는 복사생성자에서 동적할당으로 포인터가 아예 다른 곳을 가리키게끔 한 후에 값을 일일이 복사해주면 된다

- 복사대입연산자와의 차이


### 변환생성자

- 변환생성자의 사용
`Class(int rhs){}`
인자가 하나인 것이 변환생성자 개념을 특징짓는다
정수를 객체로 변환하겠다는 개념

- 임시 객체
어떤 함수의 매개변수형식이 클래스면 정수인자(임시객체)를 받을 때 변환생성자가 호출된다

- explicit 키워드의 사용
`explicit Class(int rhs){}`
변환생성자 호출 시 다른 형이 정수형으로 암시적 형변환 하는 것을 막는다



### 이동생성자

- 왼값과 오른값 참조
(왼값은 const 속성이 있는 것과 없는 것으로 분류된다)
왼값은 일반객체를 참조하고 있다
오른값은 임시객체(상수객체)를 참조하고 있다, 식별자가 없다
오른값의 생명주기
	`int a = 1;`에서 1이라는 임시 객체가 생겼다가 바로 사라진다
	`char* s = "abc";`에서는 임시 객체가 포인팅을 받고 있으므로 안 사라진다
위의 경우처럼 짧은 생명주기를 강제로 늘리기 위해 `int&& a = 1;`와 같이 쓸 수 있다
`int a = 1; int&& b = a;`는 왼값 a를 오른값 참조로 부르려는 것이기 때문에 에러
`int a = 1; int&& b = std::move(a);`로 오른값으로 변경하여 사용가능
상수객체였는데도 포인터처럼 값 변경도 가능

- 이걸 알아야 하는 이유
함수의 반환형식이 클래스일 때 임시객체가 복사생성자로 생성된다!
함수의 반환값은 오른값이므로 복사생성자에서 깊은 복사를 구현해놓았다면 오른값을 위해 동적할당을 해줘야 하는 상황이 온다는 것
동적할당된 임시객체(함수반환값)를 없애지 말고 따로 복사도 안하고 생명주기를 늘려 포인팅만 잘 시켜주면 복사를 한 번도 안 하고 힙 영역도 줄일 수 있게 된다는 것!
그래서 오른값참조가 필요
https://www.youtube.com/watch?v=GutCygNRi-I

- RVO(반환값 최적화)

- NRVO




## 스태틱

정적, 즉 런타임 동안 소멸될 수 없다는 것


1. Static variable
	Data 영역에 저장: 지역범위를 가지는 전역변수라 생각하자
	초기화:
		0으로 자동 초기화
		최초 초기화 이후 초기화는 무시됨
	불가능:
		다른 파일에서의 외부참조(extern) 불가
		매개변수로 사용 불가

2. Static object
	Data 영역에 저장
	생성자로 초기화, 0으로 초기화되지는 않음
	소멸자 main 끝날 때 자동호출

3. Static member variable
	모든 object에서 접근 및 공유
	초기화:
		privte이라 하더라도 객체 생성 전에 전역범위에서 X::v로 초기화
		최초 초기화 이후 초기화는 무시됨

4. Static member function
	외부에서 접근 및 공유
	객체 생성 없이 X::f로 호출
	static member에만 접근가능


static const vs const static
- static const
	마치 클래스로 캡슐화되는 #define과 같은 존재
	헤더 파일에서 초기화
	소스 파일에서 정의
	초기화 이후 값 변경 불가능
	초기화는 선언 시 이루어지기도 정의 시 이루어지기도
		선언 시 초기화를 막은 컴파일러도 존재

const 변수의 값은 컴파일타임에 결정





## 오버로딩
연산자 오버로딩







## 다형성



### 가상클래스
- 다중상속
암튼 피해라
범위지정연산자 :: 로 부분적 해결 가능


- 가상기반클래스
`class Base1 : virtual public SuperBase {};`
`class Base2 : virtual public SuperBase {};`
`class Derived : public Base1, public Base2 {};`
즉 기반클래스들이 가상이면 Derived가 SuperBase의 생성자를 호출하게 된다


-가상함수
Q. C++에서 virtual 키워드에 대해 설명하시오.
Q. 가상 함수가 무엇인지 설명하시오.
Q. 가상 함수의 동작 방식에 대해 설명하시오.
Q. 가상 함수 테이블에 무엇이 저장되어 있나요?


### 오버라이딩




### 가상메소드

- 동적 바인딩
객체의 형식/값이 런타임에 결정됨
void*
클래스 포인터와 상속 관계
slice of information
포인터의 형식과 읽는 방법이 다르기 때문에

- 가상메소드
가상클래스의 virtual과 그닥 상관없다고 이해하고 넘어가자
기반클래스의 메소드에만 virtual을 붙여주면 되지만 가독성을 위해 자식클래스에 virtual이나 override 를 써주는 게 관례
기반클래스 포인터 B* 로 파생클래스 객체를 가리키고 있는데도 불구하고 가상메소드를 오버라이드한 메소드를 읽으면 기반클래스의 메소드가 아니라 오버라이드된 파생클래스의 메소드가 호출된다는 것
호출하려는 메소드에 virtual이 달려있으면 파생클래스 중 오버라이드된 게 있는지 찾아서 있으면 그걸 실행한다 생각해도 될 듯
즉, B* 변수로 D1, D2 왔다갔다 하며 가리킬 수 있게 된다!

- 상속관계에서 생성자와 소멸자
일단 파생클래스의 생성자 소멸자 호출순서는 B, D, ~D, ~B 이다
소멸자를 가상으로 만들어주지 않으면 B* 가 D를 가리켜도 D의 소멸자 무시하고 B의 소멸자만 호출할 것이다
그럼 D가 가지지만 B가 가지지 못한 영역에서 메모리 누수 일어난다





- 추상클래스
순수가상함수란?
가상함수는 파생클래스에 구현된 것을 우선한다.
이때 파생클래스에 구현을 강제하는 것이 순수가상함수.

```c++
class AbstractClass
{
    virtual void abstractMemberFunction() = 0; // 순수가상함수가 있으므로 추상클래스가 됨
    virtual void abstractMemberFunction1(); // 가상함수
    void abstractMemberFunction2();
};
```

순수가상함수인 메소드를 하나 이상 가지면 추상클래스가 되어 객체를 만들 수 없게 된다.

순수가상소멸자
모든 클래스는 기본소멸자를 갖고 있다. 따라서 부모클래스의 소멸자가 순수가상함수여도 자식클래스에서 소멸자 구현을 할 필요가 없다.
순수가상함수를 가지고 있지 않은 부모클래스를 추상클래스로 만들 때 사용할 수 있다.
일반적인 순수가상함수는 자식클래스에서 구현되지만 순수가상소멸자는 아니므로 부모클래스에서 중괄호를 쳐줘서 형식적으로 구현해줘야 한다.



- 인터페이스

```c++
class IClass
{
public:
    virtual ~IClass() = default;
    virtual void move_x(int x) = 0;
    virtual void move_y(int y) = 0;
    virtual void draw() = 0;
};
```

모든 메소드를 순수가상함수로 만들어버리면 인터페이스라고 말할 수 있게 된다.
이때의 이점은 자식클래스들이 다양한 인터페이스들을 다중상속하여도 반드시 모든 메소드들을 구현해줘야 하므로 충돌을 반드시 피할 수밖에 없게 만든다는 것이다.
추상클래스는 하나만 상속한다는 약속을 하고 인터페이스는 기능에 대한 것을 추상화시키는 것이 좋다.
멤버변수는 넣지 않고 상속하는 자식클래스에 일일이 구현해주어야 한다.






# 3. STL
container
iterator
stream
algorithm
function object




## string

"aaa".str().c_str() 하지 말기

string vs const char*
- 메모리가 어디 할당되는지 전부 파악하고자 하는 게 아니면 가능한 string을 쓰자.



# 4. Template



제네릭 프로그래밍
함수 객체
	operator()를 이용하여 함수처럼 작동하는 객체를 만들 수 있다



# 5. Multi-thread


비동기 처리?

