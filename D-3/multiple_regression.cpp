#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x1(n), x2(n), y(n);

    cout << "Enter values for x1, x2 and y:\n";
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i] >> y[i];
    }

    double sum_x1 = 0, sum_x2 = 0, sum_y = 0;
    double sum_x1_sq = 0, sum_x2_sq = 0;
    double sum_x1x2 = 0, sum_x1y = 0, sum_x2y = 0;

    for (int i = 0; i < n; i++) {
        sum_x1 += x1[i];
        sum_x2 += x2[i];
        sum_y  += y[i];
        sum_x1_sq += x1[i] * x1[i];
        sum_x2_sq += x2[i] * x2[i];
        sum_x1x2 += x1[i] * x2[i];
        sum_x1y  += x1[i] * y[i];
        sum_x2y  += x2[i] * y[i];
    }

    double D = (sum_x1_sq * sum_x2_sq) - (sum_x1x2 * sum_x1x2);

    double b1 = ((sum_x2_sq * sum_x1y) - (sum_x1x2 * sum_x2y)) / D;
    double b2 = ((sum_x1_sq * sum_x2y) - (sum_x1x2 * sum_x1y)) / D;

    double mean_y = sum_y / n;
    double mean_x1 = sum_x1 / n;
    double mean_x2 = sum_x2 / n;

    double b0 = mean_y - (b1 * mean_x1) - (b2 * mean_x2);

    cout << "\nRegression Coefficients:\n";
    cout << "b0 = " << b0 << endl;
    cout << "b1 = " << b1 << endl;
    cout << "b2 = " << b2 << endl;

    double new_x1, new_x2;
    cout << "\nEnter new x1 and x2 to predict y: ";
    cin >> new_x1 >> new_x2;

    double predicted_y = b0 + b1 * new_x1 + b2 * new_x2;
    cout << "Predicted y = " << predicted_y << endl;

    return 0;
}
