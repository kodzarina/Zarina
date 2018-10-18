#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;


template<int N, int I, int J, int K>
class ExpSum {
public:
	enum { go = (K + 1 != J) };
	static inline float sum() {
		return 1 + ((float)I / N) / K*ExpSum<N*go, I*go, J*go, (K + 1)*go>::sum();
	}
};


template <int N, int I> class Exponenta {
public:
	static inline float exponenta()
	{
		return ExpSum<N, I, 38, 1>::sum();
	}
};

template <> class ExpSum<0, 0, 0, 0>
{
public:
	static inline float sum() {
		return 0;
	}
};

template <int N, int I, int J, int K> class ArcCosSum {
public:
	enum { go = (K + 2 != 2 * J) };
	static inline float sum() {
		float x = Exponenta<N, I>::exponenta();
		return ((float)1 / (K + 1) - x*x*(K + 1) / (K + 2)*ArcCosSum < N*go, I*go, J*go, (K + 2)*go>::sum());
	}
};

template <int N, int I>  class ArcCos {
public:
	static inline float acos()
	{
		float x = Exponenta<N, I>::exponenta();
		return (M_PI / 2. - x*ArcCosSum<N, I, 38, 0>::sum());
	}
};


template <> class ArcCosSum <0, 0, 0, 0> {
public:
	static inline float sum()
	{
		return 0;
	}
};

template <int N, int I, int J, int K> class LogarithmSum {
public:
	enum { go = (K != J + 1) };
	static inline float sum() {
		float x = ArcCos<N, I>::acos() - 1;
		return ((float)1 * go / K - x*LogarithmSum < N*go, I*go, J*go, (K + 1)*go>::sum());
	}
};


template <int N, int I>  class Logarithm {
public:
	static inline double ln()
	{
		float x = ArcCos<N, I>::acos() - 1;
		return (x*LogarithmSum<N, I, 38, 1>::sum());
	}
};

template <> class LogarithmSum <0, 0, 0, 0> {
public:
	static inline float sum()
	{
		return 0;
	}
};


template <int N, int I, int J, int K> class ArcTanSum{
public:
	enum { go = (K + 1 != J) };
	static inline double sum() {
	    float x = Logarithm<N, I>::ln();
    //return (float) 1 - x*x *(float) (2 * K + 2) / (2 * K + 3)*ArcTanSum < N*go, I*go, J*go, (K + 1)*go>::sum();
    //return ((float)1 * go / K - x*LogarithmSum < N*go, I*go, J*go, (K + 1)*go>::sum());
     // return  1 - x*x*(float)(2 * N - 2 * K - 1) / (2 * N - 2 * K + 1) *ArcTanSum < N*go, I*go, J*go, (K + 1)*go>::sum();
      return -(float) (2*K-1)/(2*K+1)*ArcTanSum < N*go, I*go, J*go, (K + 1)*go>::sum();
//      return ((float)1 * go /(2 * K - 2 * K - 1) / (2 * K - 2 * K + 1)*ArcTanSum < N*go, I*go, J*go, (K + 1)*go>::sum());
	}
};

template <int N, int I>  class ArcTan {
public:
	static inline double atan()
	{
		float x = Logarithm<N, I>::ln();
		return (x*ArcTanSum<N, I, 38, 0>::sum());
	}
};

template <> class ArcTanSum <0, 0, 0, 0> {
public:
	static inline double sum()
	{
		return 1;
	}
};


template <int N, int I, int J, int K> class SineSum {
public:
	enum { go = (K + 1 != J) };
	static inline double sum() {
		float x = ArcTan<N, I>::atan();
		return 1 - x*x / (2 * K + 2) / (2 * K + 3)*SineSum < N*go, I*go, J*go, (K + 1)*go>::sum();
	}
};


template <int N, int I>  class Sin {
public:
	static inline double sin()
	{
		float x = ArcTan<N, I>::atan();
		return (x*SineSum<N, I, 38, 0>::sum());
	}
};


template <> class SineSum <0, 0, 0, 0> {
public:
	static inline double sum()
	{
		return 1;
	}
};

int main()
{
	float a = Sin<-2, 1>::sin();
	cout << "Metaprogram:      "<< a << endl;
	float b = sin(atan(log(acos(exp(-0.5)))));
	cout << "Standard program: "<< b << endl;
	cout << "Error:             "<<abs(a-b)<<endl;
	system("pause");
	return 0;
}


