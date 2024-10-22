struct point {
    ld x,y;
    point() {x=y=0.0;}
    point(ld x, ld y) : x(x), y(y) {}

    bool operator< (point other) const {
        if(fabs(x-other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator==(const point &other) const {
        return (fabs(x-other.x)<EPS) and (fabs(y-other.y)<EPS);
    }
};
ld dist(const point &p1, const point &p2) {
    return hypot(p1.x-p2.x, p1.y-p2.y);
}
ld deg_to_rad(ld d) {
    return d*PI / 180.0;
}
ld rad_to_deg(ld r) {
    return r*180.0 / PI;
}
point rotate(const point &p, ld theta) {
    ld rad = deg_to_rad(theta);
    return point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}
struct line {ld a,b,c;};
void points_to_line(const point &p1, const point &p2, line &l) {
    if(cmp_d(p1.x, p2.x) == -1)
        l = {1.0, 0.0, -p1.x};
    else
        l = {-(ld)(p1.y-p2.y) / (p1.x-p2.x), 1.0, -(ld)(l.a*p1.x)-p1.y};
}
void point_slope_to_line(point p, ld m, line &l) {
    l.a = -m;
    l.b = 1.0;
    l.c = -((l.a*p.x) + (l.b*p.y));
}
bool parallel(line l1, line l2) {
    return cmp_d(l1.a, l2.a)==-1 and cmp_d(l1.b,l2.b)==-1;
}
bool same(line l1, line l2) {
    return parallel(l1,l2) and cmp_d(l1.c,l2.c)==-1;
}
bool intersect(line l1, line l2, point &p) {
    if(parallel(l1,l2)) return false;
    p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);

    if(fabs(l1.b)>EPS) p.y = -(l1.a*p.x + l1.c); // test for vertical line to avoid division by 0
    else               p.y = -(l2.a*p.x + l2.c);

    return true;
}
struct vec {
    ld x,y;
    vec(ld x, ld y) : x(x), y(y) {}
};
vec to_vec(const point &a, const point &b) {
    return {b.x-a.x, b.y-a.y};
}
vec scale(const vec &v, ld s) {
    return {v.x*s, v.y*s};
}
point translate(const point &p, const vec &v) {
    return {p.x+v.x, p.y+v.y}; // translate p according to v
}
ld dot(vec a, vec b) {
    return a.x*b.x + a.y*b.y;
}
ld norm_sq(vec v) {
    return v.x*v.x + v.y*v.y;
}
ld angle(const point &a, const point &b, const point &c) {
    vec ba=to_vec(b,a), bc=to_vec(b,c);
    return acos( dot(ba,bc) / sqrt(norm_sq(ba) * norm_sq(bc)) );
}
ld cross(vec a, vec b) {
    return a.x*b.y - a.y*b.x;
}
bool CCW(point p, point q, point r) {
    vec pq = to_vec(p,q), pr = to_vec(p,r);
    return cross(pq,pr) > EPS; // return true if point r is on the left side of line pq
}
bool collinear(point p, point q, point r) {
    vec pq = to_vec(p,q), pr = to_vec(p,r);
    return fabs(cross(pq,pr)) < EPS; // return true if point r is on the same line as the line pq
}
ld dist_to_line(point p, point a, point b, point &c) {
    vec ap = to_vec(a,p), ab = to_vec(a,b);
    ld u = dot(ap,ab) / norm_sq(ab);

    // forumula: c = a + u*ab;
    c = translate(a, scale(ab,u)); // translate a to c
    return dist(p,c);
}
ld dist_to_seg(point p, point a, point b, point &c) {
    vec ap = to_vec(a,p), ab = to_vec(a,b);
    ld u = dot(ap,ab) / norm_sq(ab);

    if(u < 0.0) { // closer to a
        c = point(a.x,a.y);
        return dist(p,a);
    }
    if(u > 1.0) { // closer to b
        c = point(b.x,b.y);
        return dist(p,b);
    }
    return dist_to_line(p,a,b,c);
}
