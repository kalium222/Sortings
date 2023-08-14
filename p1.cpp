#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point_2D {
public:
    int x;
    int y;
    Point_2D* min_point_pointor;

    Point_2D(int x=0, int y=0) {
        this->x = x;
        this->y = y;
    }

    int ccw(const Point_2D &p2, const Point_2D &p3) const {       //p1.ccw(p2, p3) == ccw(p1, p2, p3);
        return (p2.x-this->x)*(p3.y-this->y) - (p2.y-this->y)*(p3.x-this->x);
    }

    // bool operator < (const Point_2D p3) {
    //     if ( (this->min_point_pointor)->ccw(*this,p3)>0 ) return true;
    //     else return false;
    // }

};

bool operator < (const Point_2D &p1, const Point_2D &p2) {
    return (p1.min_point_pointor)->ccw(p1,p2)>0;
}

int main() {
    int n = 0;
    vector<Point_2D> s;
    vector<Point_2D> all_points;
    cin >> n;
    if (n==0) return 0;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        all_points.push_back(Point_2D(x,y));
    }

    // cout << "N: " << n << endl;
    // cout << "initial point set" << endl;
    // for (auto item:all_points) {
    //     cout << item.x << " " << item.y << endl;
    // }


    int p0_x = all_points[0].x;
    int p0_y = all_points[0].y;
    int p0_index = 0;
    for (int i=0; i<n; i++) {
        if (all_points[i].y<p0_y||(all_points[i].y==p0_y&&all_points[i].x<p0_x)) {
            p0_y = all_points[i].y;
            p0_x = all_points[i].x;
            p0_index = i;
        } 
    }
    for (int i=0; i<n; i++) {
        all_points[i].min_point_pointor = &all_points[p0_index];
    }

    // cout << "P0: " << p0_x << " " << p0_y << endl; 
    
    
    s.push_back(all_points[p0_index]);
    all_points.erase(all_points.begin()+p0_index);
    sort(all_points.begin(),all_points.end(),[=](Point_2D p2, Point_2D p3){return ((p2.x-p0_x)*(p3.y-p0_y)-(p3.x-p0_x)*(p2.y-p0_y)>0);});

    // [=](Point_2D p2, Point_2D p3){return ((p2.x-p0_x)*(p3.y-p0_y)-(p3.x-p0_x)*(p2.y-p0_y)>0);
    // cout << "sorted point set" << endl;
    // for (auto item:all_points) {
    //     cout << item.x << " " << item.y << endl;
    // }

    for (int i=0; i<(int)all_points.size(); i++) {
        while (s.size()>1 && (s[s.size()-2].ccw(s[s.size()-1], all_points[i])<=0) ) {
            s.pop_back();
        }
        s.push_back(all_points[i]);
    }

    // cout << "output: " << endl;
    for (int i=0; i<(int)s.size(); i++) {
        if (i<(int)s.size()-1 && (s[i].x==s[i+1].x && s[i].y==s[i+1].y)) {
        } else cout << s[i].x << " " << s[i].y << endl;
    }

    return 0;
}
