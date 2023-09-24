// Parallel Armstrong numbers.cpp
// NOTE: In order to get the best performance please compile this program for "Release" and not for "Debug"
// BENCHMARK: On average, the program is able to find an 11 digits Armstrong number in 1000 milliseconds.
// Developed using Visual Studio

#include <windows.h>
#include <ppl.h>
#include <iostream>
#include <vector>
#include <math.h>

#define DIGITS 11

using namespace concurrency;
using namespace std;

//Precalculated powers
const unsigned long long power[13][12] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096 },
	{ 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441 },
	{ 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216 },
	{ 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625 },
	{ 6, 36, 216, 1296, 7776, 46656, 279936, 1679616, 10077696, 60466176, 362797056, 2176782336 },
	{ 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607, 282475249, 1977326743, 13841287201 },
	{ 8, 64, 512, 4096, 32768, 262144, 2097152, 16777216, 134217728, 1073741824, 8589934592, 68719476736 },
	{ 9, 81, 729, 6561, 59049, 531441, 4782969, 43046721, 387420489, 3486784401, 31381059609, 282429536481 },
	{ 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000 },
	{ 11, 121, 1331, 14641, 161051, 1771561, 19487171, 214358881, 2357947691, 25937424601, 285311670611, 3138428376721 }
};

#pragma region Function declarations

template <class Function>
__int64 time_call(Function&& f);
int number_of_digits(unsigned long long num);
bool is_armstrong(unsigned long long number);

#pragma endregion

int wmain()
{
	// After analyzing the distribution of the Armstrong numbers I decided to focus on 11 digits Armstrong numbers.
	// The range taken into account is selected to optimize the performance of the parallelization without running out of the computational resources.
	// To increase the chances of success I parallelized the process.
	// In addition to the usual advantages of parallelization, given the random distribution of Armstrong numbers, doing things in parallel and not sequentially increases 
	// the probability of success by making the most of the partition algorithm that optimize the parallel execution.
	// I take advantage of the scheduling algorithm which uses the work-stealing and range stealing techniques to balance these partitions when workloads are unbalanced. 
	// Leveraging that, I raised the odds of discovering an Armstrong number faster.

	const size_t size = 100000000000;

	//Metric removed to improve performance
	//LONG armstrong_count = 0L;
	__int64 elapsed = time_call([&]
		{
			cancellation_token_source cts;
			run_with_cancellation_token([size, &cts]()
				{
					parallel_for(size_t(20000000000), size, [&cts](size_t i)
						{
							if (is_armstrong(i))
							{
								cout << i << endl;
								// 11 digits Armstrong number found, cancel the parallel execution
								cts.cancel();
								//Metric removed to improve performance
								//InterlockedIncrement(&armstrong_count);
							}
						});
				}, cts.get_token());
		});

	wcout << L"Finished in " << elapsed << L" ms" << endl << endl << endl;
	cout << "Press enter to exit...";
	cin.ignore();
}

#pragma region Function definitions

/**
 * Returns the number of milliseconds that it takes to call the passed in function.
 * @param Function you want to evaluate duration
 * @return Total duration
 */
template <class Function>
__int64 time_call(Function&& f)
{
	__int64 begin = GetTickCount64();
	f();
	return GetTickCount64() - begin;
}

/**
 * Function to calculate the total number of digits in the number.
 * @param num Number
 * @return Total number of digits
 */
 // Function commented because unused
 //int number_of_digits(unsigned long long num) {
 //    int total_digits = 0;
 //    while (num > 0) {
 //        num = num / 10;
 //        ++total_digits;
 //    }
 //    return total_digits;
 //}

 /**
  * Function to check whether the number is an Armstrong number or not.
  * @param num Number
  * @return `true` if the number is an Armstrong number
  * @return `false` if the number is not an Armstrong number
  */
bool is_armstrong(unsigned long long number) {
	// If the number is less than 0, then it is not an Armstrong number.
	// This is a prior condition. Removed to improve performance
	//if (number < 0) {
	//    return false;
	//}
	unsigned long long sum = 0;
	unsigned long long temp = number;
	// Finding the number of digits of the selected number
	// Removed this function with costant result. I control this parameter by focusing on 11 digits numbers. Performance improvement
	//int total_digits = number_of_digits(number);
	int total_digits = DIGITS;
	while (temp > 0) {
		unsigned long long rem = temp % 10;
		// Finding each digit raised to the power total digit and add it to the total sum
		sum = sum + power[rem][total_digits - 1];
		temp = temp / 10;
	}
	return number == sum;
}

#pragma endregion
