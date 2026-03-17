//#include <iostream>
//using namespace std;
//
//class Employee {
//public:
//    virtual float calculateSalary() = 0;  
//};
//
//class FullTimeEmployee : public Employee {
//    private:
//        float fixedSalary;
//
//        public:
//            FullTimeEmployee(float s) {
//                fixedSalary = s;
//            }
//
//         float calculateSalary() {
//            return fixedSalary; 
//           }
//};
//
//class PartTimeEmployee : public Employee {
//private:
// int hoursWorked;
//    float hourlyRate;
//
//public:
//        PartTimeEmployee(int h, float r) {
//            hoursWorked = h;
//            hourlyRate = r;
//        }
//
//        float calculateSalary() {
//
//
//            return hoursWorked * hourlyRate;
//        }
//};
//
//int main() {
//    FullTimeEmployee emp1(50000);
//    PartTimeEmployee emp2(5, 1000);
//
//    cout << "Full Time Emp Salary = " << emp1.calculateSalary() << endl;
//    cout << "Part Time Emp Salary = " << emp2.calculateSalary() << endl;
//
//    return 0;
//}