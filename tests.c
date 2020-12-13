#include "Unity/unity.h"
#include "include/header.h"

void setUp(){};

void tearDown(){};

void test_tuple()
{
	t_tuple  ponto;
	ponto.x = 4.3;
	ponto.y = -4.2;
	ponto.z = 3.1;
	ponto.w = 1.0;
	
	TEST_MESSAGE("Point test");	
	TEST_ASSERT_FLOAT_WITHIN(0.01, 4.3, ponto.x);
	TEST_ASSERT_FLOAT_WITHIN(0.01, -4.2, ponto.y);
	TEST_ASSERT_FLOAT_WITHIN(0.01, 3.1, ponto.z);
	TEST_ASSERT_FLOAT_WITHIN(0.01, 1.0, ponto.w);
	
	t_tuple  vetor;
        vetor.x = 4.3;
        vetor.y = -4.2;
        vetor.z = 3.1;
        vetor.w = 0.0;

	TEST_MESSAGE("Vector test");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 4.3, vetor.x);
        TEST_ASSERT_FLOAT_WITHIN(0.01, -4.2, vetor.y);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 3.1, vetor.z);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.0, vetor.w);
}

void test_point()
{
	t_tuple  ponto;
	ponto = point(4.3, -4.2, 3.1);

        TEST_MESSAGE("Function point test");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 4.3, ponto.x);
        TEST_ASSERT_FLOAT_WITHIN(0.01, -4.2, ponto.y);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 3.1, ponto.z);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 1.0, ponto.w);
}

void test_vector()
{
        t_tuple  vetor;
        vetor = vector(4.3, -4.2, 3.1);

        TEST_MESSAGE("Function vector test");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 4.3, vetor.x);
        TEST_ASSERT_FLOAT_WITHIN(0.01, -4.2, vetor.y);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 3.1, vetor.z);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.0, vetor.w);
}

void test_isEqual()
{
        t_tuple  v1;
        t_tuple  v2;
        v1 = vector(4.3, -4.2, 3.1);
        v2 = vector(4.3, -4.2, 5.1);

	TEST_MESSAGE("Function isEqual test");
	TEST_ASSERT_TRUE(isEqual(v1,v1));
	TEST_ASSERT_FALSE(isEqual(v1,v2));
}

void test_add()
{
        t_tuple  v1;
        v1.x = 3;
        v1.y = -2;
        v1.z = 5;
        v1.w = 1;

        t_tuple  v2;
        v2.x = -2;
        v2.y = 3;
        v2.z = 1;
        v2.w = 0;

       	t_tuple  v3;
        v3.x = 1;
        v3.y = 1;
        v3.z = 6;
        v3.w = 1;

        TEST_MESSAGE("Function add test");
        TEST_ASSERT_TRUE(isEqual(add(v1,v2),v3));
}


void test_sub()
{
	t_tuple  p1;
        p1 = point(3, 2, 1);

	t_tuple  p2;
        p2 = point(5, 6, 7);

        t_tuple  v3;
        v3 = vector(-2, -4, -6);
        
	TEST_MESSAGE("Function sub  point point");
        TEST_ASSERT_TRUE(isEqual(sub(p1,p2), v3));

	t_tuple  v4;
        v4 = vector(5, 6, 7);

        t_tuple  p5;
        p5 = point(-2, -4, -6);

	TEST_MESSAGE("Function sub  point vector");
        TEST_ASSERT_TRUE(isEqual(sub(p1,v4), p5));

        t_tuple  v6;
        v6 = vector(3, 2, 1);

        TEST_MESSAGE("Function sub  vector vector");
        TEST_ASSERT_TRUE(isEqual(sub(v6,v4), v3));

}

void test_negate()
{
        t_tuple  v1;
        v1.x = 1;
        v1.y = -2;
        v1.z = 3;
        v1.w = -4;

        t_tuple  v2;
        v2.x = -1;
        v2.y = 2;
        v2.z = -3;
        v2.w = 4;

        TEST_MESSAGE("Function negate");
        TEST_ASSERT_TRUE(isEqual(negate(v1), v2));

}

void test_multi()
{
        t_tuple  v1;
        v1.x = 1;
        v1.y = -2;
        v1.z = 3;
        v1.w = -4;

        t_tuple  v2;
        v2.x = 3.5;
        v2.y = -7;
        v2.z = 10.5;
        v2.w = -14;

        TEST_MESSAGE("Function multi");
        TEST_ASSERT_TRUE(isEqual(multi(v1, 3.5), v2));

}

void test_divide()
{
        t_tuple  v1;
        v1.x = 1;
        v1.y = -2;
        v1.z = 3;
        v1.w = -4;

        t_tuple  v2;
        v2.x = 0.5;
        v2.y = -1;
        v2.z = 1.5;
        v2.w = -2;

        TEST_MESSAGE("Function divide");
        TEST_ASSERT_TRUE(isEqual(divide(v1, 2), v2));

}

void test_magnitude()
{
	t_tuple  v1;
	t_tuple  v2;
	t_tuple  v3;
	t_tuple  v4;
	t_tuple  v5;

	v1 = vector(1,0,0);
	v2 = vector(0,1,0);
	v3 = vector(0,0,1);
	v4 = vector(1,2,3);
	v5 = vector(-1,-2,-3);
	
	TEST_MESSAGE("Function magnitude");
	TEST_ASSERT_FLOAT_WITHIN(0.01, 1, magnitude(v1));
	TEST_ASSERT_FLOAT_WITHIN(0.01, 1, magnitude(v2));
	TEST_ASSERT_FLOAT_WITHIN(0.01, 1, magnitude(v3));
	TEST_ASSERT_FLOAT_WITHIN(0.01, sqrt(14), magnitude(v4));
	TEST_ASSERT_FLOAT_WITHIN(0.01, sqrt(14), magnitude(v5));

}

void test_normalize()
{
        t_tuple  v1;
        t_tuple  v2;
        t_tuple  v3;
        t_tuple  v4;

	v1 = vector(4,0,0);
	v2 = vector(1,0,0);
	v3 = vector(1,2,3);
	v4 = vector(1/sqrt(14),2/sqrt(14),3/sqrt(14));
	
	TEST_MESSAGE("Function normalize");
        TEST_ASSERT_TRUE(isEqual(normalize(v1), v2));
  	TEST_ASSERT_FLOAT_WITHIN(0.01, 1, magnitude(normalize(v1)));
        TEST_ASSERT_TRUE(isEqual(normalize(v3), v4));
	TEST_ASSERT_FLOAT_WITHIN(0.01, 1, magnitude(normalize(v3)));

}

void test_dot()
{
        t_tuple  v1;
        t_tuple  v2;

	v1 = vector(1,2,3);
	v2 = vector(2,3,4);
        TEST_MESSAGE("Function dot product");
	TEST_ASSERT_FLOAT_WITHIN(0.01, 20, dot(v1, v2));
}

void test_cross()
{
        t_tuple  v1;
        t_tuple  v2;
        t_tuple  v3;
        t_tuple  v4;

        v1 = vector(1,2,3);
        v2 = vector(2,3,4);
        v3 = vector(-1,2,-1);
        v4 = vector(1,-2,1);        

	TEST_MESSAGE("Function cross product");
        TEST_ASSERT_TRUE(isEqual(cross(v1, v2), v3));
        TEST_ASSERT_TRUE(isEqual(cross(v2, v1), v4));
}

void test_tick()
{
	t_projectile p1;
	t_projectile p2;
	t_projectile resp;
	t_enviroment env;

	p1.position = point(0,1,0);
	p1.velocity = normalize(vector(1,1,0));
	
        p2.position = point(1/sqrt(2), 1/sqrt(2) + 1, 0);
        p2.velocity = vector(1/sqrt(2) - 0.01, 1/sqrt(2) - 0.1, 0);

	env.gravity = vector(0,-0.1,0);
	env.wind = vector(-0.01,0,0);
        
	resp = tick(env, p1);

	TEST_MESSAGE("Function tick");
        TEST_ASSERT_TRUE(isEqual(p2.position, resp.position));
	TEST_ASSERT_TRUE(isEqual(p2.velocity, resp.velocity));
}

void test_color()
{
	t_color  c;
	c = color(-0.5, 0.4, 1.7);

        TEST_MESSAGE("Point color");
        TEST_ASSERT_FLOAT_WITHIN(0.01, -0.5, c.red);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.4, c.green);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 1.7, c.blue);
}


void test_addcolor()
{
        t_color  c1;
        t_color  c2;
	t_color  c3;

        c1 = color(0.9, 0.6, 0.75);        
	c2 = color(0.7, 0.1, 0.25);
       	c3 = addcolor(c1, c2);

        TEST_MESSAGE("Function addcolor");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 1.6, c3.red);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.7, c3.green);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 1.0, c3.blue);
}

void test_subcolor()
{
        t_color  c1;
        t_color  c2;
        t_color  c3;

        c1 = color(0.9, 0.6, 0.75);
        c2 = color(0.7, 0.1, 0.25);
        c3 = subcolor(c1, c2);

        TEST_MESSAGE("Function subcolor");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.2, c3.red);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.5, c3.green);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.5, c3.blue);
}

void test_multicolorS()
{
        t_color  c1;
        t_color  c2;

        c1 = color(0.2, 0.3, 0.4);
        c2 = multicolorS(c1, 2);

        TEST_MESSAGE("Function multicolorS");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.4, c2.red);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.6, c2.green);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.8, c2.blue);
}

void test_multicolorV()
{
        t_color  c1;
        t_color  c2;
        t_color  c3;

        c1 = color(1, 0.2, 0.4);
        c2 = color(0.9, 1, 0.1);
        c3 = multicolorV(c1, c2);

        TEST_MESSAGE("Function multicolorV");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.9, c3.red);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.2, c3.green);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 0.04, c3.blue);
}

void test_isColorEqual()
{
        t_color  c1;
	t_color  c2;
	c1  = color(0.5, 0.01, 0.2);        
	c2  = color(0.75, 0.1, 1.2);

        TEST_MESSAGE("Function isColorEqual test");
        TEST_ASSERT_TRUE(isColorEqual(c1,c1));
        TEST_ASSERT_FALSE(isColorEqual(c1,c2));
}

void test_canvas()
{
	t_canvas c;
	t_color black;
	int i;
	int j;
	int w;
	int h;

	i = 0;
	w = 10;
	h = 20;
	black = color(0,0,0);
	c = canvas(w, h);
	TEST_MESSAGE("Function canvas test");
	TEST_ASSERT_EQUAL(w, c.width);
	TEST_ASSERT_EQUAL(h, c.height);
	while (i < w)
	{
		j = 0;
		while (j < h)
        	{
			TEST_ASSERT_TRUE(isColorEqual(c.pixel[i][j], black));
			j++;
		}
		i++;
	}
}

void test_writePixel()
{
	t_canvas c;	
	t_color red;
	int w;
        int h;

        w = 10;
        h = 20;
        c = canvas(w, h);
	red = color(1,0,0);
	writePixel(&c, 2, 3, red);
	TEST_MESSAGE("Function writePixel test");
	TEST_ASSERT_TRUE(isColorEqual(c.pixel[2][3], red));	
}

void test_canvas_to_ppm()
{
	t_canvas c;
	t_color c1;
	t_color c2;
	t_color c3;	
	int w;
	int h;

	c1 = color(1.5,0,0);
	c2 = color(0,0.5,0);
	c3 = color(-0.5,0,1);
	char *ppm = "P3\n5 3\n255\n255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";
	w = 5;
	h = 3;
	c = canvas(w, h);
	writePixel(&c, 0, 0, c1);
	writePixel(&c, 1, 2, c2);
	writePixel(&c, 2, 4, c3);
	TEST_MESSAGE("Function canvas_to_ppm test");
	TEST_ASSERT_EQUAL_STRING(ppm, canvas_to_ppm(&c));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_tuple);
	RUN_TEST(test_point);
	RUN_TEST(test_vector);
	RUN_TEST(test_isEqual);
	RUN_TEST(test_add);
	RUN_TEST(test_sub);
	RUN_TEST(test_negate);
 	RUN_TEST(test_multi);
	RUN_TEST(test_divide);	
	RUN_TEST(test_magnitude);
	RUN_TEST(test_normalize);
	RUN_TEST(test_dot);
	RUN_TEST(test_cross);
	RUN_TEST(test_tick);
	RUN_TEST(test_color);
	RUN_TEST(test_addcolor);
	RUN_TEST(test_subcolor);
	RUN_TEST(test_multicolorS);
	RUN_TEST(test_multicolorV);
	RUN_TEST(test_isColorEqual);
	RUN_TEST(test_canvas);
	RUN_TEST(test_writePixel);
	RUN_TEST(test_canvas_to_ppm);
	return UNITY_END();
}
