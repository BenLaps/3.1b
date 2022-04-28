#include "pch.h"
#include "CppUnitTest.h"
#include "../3.1b/3.1b.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Student* s = new Student[N];
			s->prizv = "Protsak";
			s->cours = (Cours)2;
			s->spec = (Spec)2;
			s->physic = 5;
			s->prog = 5;
			s->math = 5;

			Assert::IsTrue(Excellent(s, N) > 0);
		}
	};
}
