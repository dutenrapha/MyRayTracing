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
	TEST_ASSERT_TRUE(isColorEqual(c.pixel[3][2], red));	
}

void test_canvas_to_ppm()
{
	t_canvas c;
	t_color c1;
	t_color c2;
	t_color c3;	
	int w;
	int h;
rotation_y
	c1 = color(1.5,0,0);
	c2 = color(0,0.5,0);
	c3 = color(-0.5,0,1);
	char *ppm = "P3\n5 3\n255\n255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";
	w = 5;
	h = 3;
	c = canvas(w, h);
	writePixel(&c, 0, 0, c1);
	writePixel(&c, 2, 1, c2);
	writePixel(&c, 4, 2, c3);
	TEST_MESSAGE("Function canvas_to_ppm test");
	TEST_ASSERT_EQUAL_STRING(ppm, canvas_to_ppm(&c));
}

void test_matrix()
{
	t_matrix M4;
	
	M4 = matrix(4);
	writeMatrix(&M4,0,0,1.0);
	writeMatrix(&M4,0,1,2.0);
	writeMatrix(&M4,0,2,3.0);
	writeMatrix(&M4,0,3,4.0);

        writeMatrix(&M4,1,0,5.5);
        writeMatrix(&M4,1,1,6.5);
        writeMatrix(&M4,1,2,7.5);
        writeMatrix(&M4,1,3,8.5);

        writeMatrix(&M4,2,0,9.0);
        writeMatrix(&M4,2,1,10.0);
        writeMatrix(&M4,2,2,11.0);
        writeMatrix(&M4,2,3,12.0);

        writeMatrix(&M4,3,0,13.5);
        writeMatrix(&M4,3,1,14.5);
        writeMatrix(&M4,3,2,15.5);
        writeMatrix(&M4,3,3,16.5);

        TEST_MESSAGE("Function matrix dim 4");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 1, M4.element[0][0]);
   	TEST_ASSERT_FLOAT_WITHIN(0.01, 4, M4.element[0][3]);	
   	TEST_ASSERT_FLOAT_WITHIN(0.01, 5.5, M4.element[1][0]);
   	TEST_ASSERT_FLOAT_WITHIN(0.01, 7.5, M4.element[1][2]);
   	TEST_ASSERT_FLOAT_WITHIN(0.01, 11, M4.element[2][2]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 13.5, M4.element[3][0]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 15.5, M4.element[3][2]);

	t_matrix M2;

        M2 = matrix(2);
        writeMatrix(&M2,0,0,-3.0);
        writeMatrix(&M2,0,1,5.0);
        writeMatrix(&M2,1,0,1.0);
        writeMatrix(&M2,1,1,-2.0);

        TEST_MESSAGE("Function matrix dim 2");
        TEST_ASSERT_FLOAT_WITHIN(0.01, -3.0, M2.element[0][0]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 5.0, M2.element[0][1]);

        TEST_ASSERT_FLOAT_WITHIN(0.01, 1.0, M2.element[1][0]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, -2.0, M2.element[1][1]);
	
       	t_matrix M3;

        M3 = matrix(3);
        writeMatrix(&M3,0,0,-3.0);
        writeMatrix(&M3,0,1,5.0);
        writeMatrix(&M3,0,2,0.0);

        writeMatrix(&M3,1,0,1.0);
        writeMatrix(&M3,1,1,-2.0);
        writeMatrix(&M3,1,2,-7.0);

        writeMatrix(&M3,2,0,0.0);
        writeMatrix(&M3,2,1,1.0);
        writeMatrix(&M3,2,2,1.0);

        TEST_MESSAGE("Function matrix dim 3");
        TEST_ASSERT_FLOAT_WITHIN(0.01, -3.0, M3.element[0][0]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, -2.0, M3.element[1][1]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 1.0, M3.element[2][2]);

}

void test_isMatrixEqual()
{
	t_matrix A;
	t_matrix B;

	A = matrix(4);
	B = matrix(4);
	
	writeMatrix(&A,0,0,1.0);
        writeMatrix(&A,0,1,2.0);
        writeMatrix(&A,0,2,3.0);
        writeMatrix(&A,0,3,4.0);

        writeMatrix(&A,1,0,5.0);
        writeMatrix(&A,1,1,6.0);
        writeMatrix(&A,1,2,7.0);
        writeMatrix(&A,1,3,8.0);

        writeMatrix(&A,2,0,9.0);
        writeMatrix(&A,2,1,8.0);
        writeMatrix(&A,2,2,7.0);
        writeMatrix(&A,2,3,6.0);

        writeMatrix(&A,3,0,5.0);
        writeMatrix(&A,3,1,4.0);
        writeMatrix(&A,3,2,3.0);
        writeMatrix(&A,3,3,2.0);

        writeMatrix(&B,0,0,2.0);
        writeMatrix(&B,0,1,3.0);
        writeMatrix(&B,0,2,4.0);
        writeMatrix(&B,0,3,5.0);

        writeMatrix(&B,1,0,6.0);
        writeMatrix(&B,1,1,7.0);
        writeMatrix(&B,1,2,8.0);
        writeMatrix(&B,1,3,9.0);

        writeMatrix(&B,2,0,8.0);
        writeMatrix(&B,2,1,7.0);
        writeMatrix(&B,2,2,6.0);
        writeMatrix(&B,2,3,5.0);

        writeMatrix(&B,3,0,4.0);
        writeMatrix(&B,3,1,3.0);
        writeMatrix(&B,3,2,2.0);
        writeMatrix(&B,3,3,1.0);
	
        TEST_MESSAGE("Function is matrix multi");
        TEST_ASSERT_TRUE(isMatrixEqual(A,A));
        TEST_ASSERT_TRUE(!isMatrixEqual(A,B));
}

void test_matrixMulti()
{
        t_matrix A;
        t_matrix B;
	t_matrix AB;
	
        A = matrix(4);
        B = matrix(4);

        writeMatrix(&A,0,0,1.0);
        writeMatrix(&A,0,1,2.0);
        writeMatrix(&A,0,2,3.0);
        writeMatrix(&A,0,3,4.0);

        writeMatrix(&A,1,0,5.0);
        writeMatrix(&A,1,1,6.0);
        writeMatrix(&A,1,2,7.0);
        writeMatrix(&A,1,3,8.0);

        writeMatrix(&A,2,0,9.0);
        writeMatrix(&A,2,1,8.0);
        writeMatrix(&A,2,2,7.0);
        writeMatrix(&A,2,3,6.0);

        writeMatrix(&A,3,0,5.0);
        writeMatrix(&A,3,1,4.0);
        writeMatrix(&A,3,2,3.0);
        writeMatrix(&A,3,3,2.0);

        writeMatrix(&B,0,0,-2.0);
        writeMatrix(&B,0,1,1.0);
        writeMatrix(&B,0,2,2.0);
        writeMatrix(&B,0,3,3.0);

        writeMatrix(&B,1,0,3.0);
        writeMatrix(&B,1,1,2.0);
        writeMatrix(&B,1,2,1.0);
        writeMatrix(&B,1,3,-1.0);

        writeMatrix(&B,2,0,4.0);
        writeMatrix(&B,2,1,3.0);
        writeMatrix(&B,2,2,6.0);
        writeMatrix(&B,2,3,5.0);

        writeMatrix(&B,3,0,1.0);
        writeMatrix(&B,3,1,2.0);
        writeMatrix(&B,3,2,7.0);
        writeMatrix(&B,3,3,8.0);

        AB = matrixMulti(A,B);
        TEST_MESSAGE("Function is equal matrix");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 20, AB.element[0][0]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 22, AB.element[0][1]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 50, AB.element[0][2]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 48, AB.element[0][3]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 44, AB.element[1][0]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 54, AB.element[1][1]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 114, AB.element[1][2]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 108, AB.element[1][3]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 40, AB.element[2][0]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 58, AB.element[2][1]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 110, AB.element[2][2]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 102, AB.element[2][3]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 16, AB.element[3][0]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 26, AB.element[3][1]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 46, AB.element[3][2]);
        TEST_ASSERT_FLOAT_WITHIN(0.01, 42, AB.element[3][3]);
}

void test_matrixMultiVec()
{
        t_matrix A;
	t_tuple b;
	t_tuple Ab;	
	t_tuple resp;

        A = matrix(4);

        writeMatrix(&A,0,0,1.0);
        writeMatrix(&A,0,1,2.0);
        writeMatrix(&A,0,2,3.0);
        writeMatrix(&A,0,3,4.0);

        writeMatrix(&A,1,0,2.0);
        writeMatrix(&A,1,1,4.0);
        writeMatrix(&A,1,2,4.0);
        writeMatrix(&A,1,3,2.0);

        writeMatrix(&A,2,0,8.0);
        writeMatrix(&A,2,1,6.0);
        writeMatrix(&A,2,2,4.0);
        writeMatrix(&A,2,3,1.0);

        writeMatrix(&A,3,0,0.0);
        writeMatrix(&A,3,1,0.0);
        writeMatrix(&A,3,2,0.0);
        writeMatrix(&A,3,3,1.0);

	b = point(1, 2, 3);
	Ab = matrixMultiVec(A,b);
	resp = point(18,24,33);
	TEST_MESSAGE("Function matrix Multi Vec");
	TEST_ASSERT_TRUE(isEqual(resp, Ab));
}

void test_matrixIdenty()
{
        t_matrix A;
	t_matrix B;
        t_matrix resp;

        A = matrix(4);

        writeMatrix(&A,0,0,1.0);
        writeMatrix(&A,0,1,0.0);
        writeMatrix(&A,0,2,0.0);
        writeMatrix(&A,0,3,0.0);

        writeMatrix(&A,1,0,0.0);
        writeMatrix(&A,1,1,1.0);
        writeMatrix(&A,1,2,0.0);
        writeMatrix(&A,1,3,0.0);

        writeMatrix(&A,2,0,0.0);
        writeMatrix(&A,2,1,0.0);
        writeMatrix(&A,2,2,1.0);
        writeMatrix(&A,2,3,0.0);

        writeMatrix(&A,3,0,0.0);
        writeMatrix(&A,3,1,0.0);
        writeMatrix(&A,3,2,0.0);
        writeMatrix(&A,3,3,1.0);
	
	B = matrix(4);

        writeMatrix(&B,0,0,-2.0);
        writeMatrix(&B,0,1,1.0);
        writeMatrix(&B,0,2,2.0);
        writeMatrix(&B,0,3,3.0);

        writeMatrix(&B,1,0,3.0);
        writeMatrix(&B,1,1,2.0);
        writeMatrix(&B,1,2,1.0);
        writeMatrix(&B,1,3,-1.0);

        writeMatrix(&B,2,0,4.0);
        writeMatrix(&B,2,1,3.0);
        writeMatrix(&B,2,2,6.0);
        writeMatrix(&B,2,3,5.0);

        writeMatrix(&B,3,0,1.0);
        writeMatrix(&B,3,1,2.0);
        writeMatrix(&B,3,2,7.0);
        writeMatrix(&B,3,3,8.0);
	

	resp = identity();
	TEST_MESSAGE("Function matrix Identy");
        TEST_ASSERT_TRUE(isMatrixEqual(resp, A));
	TEST_ASSERT_TRUE(isMatrixEqual(B, matrixMulti(B,resp)));
}

void test_matrixTranspose()
{
        t_matrix A;
	t_matrix B;
        t_matrix I;

        A = matrix(4);

        writeMatrix(&A,0,0,0.0);
        writeMatrix(&A,0,1,9.0);
        writeMatrix(&A,0,2,3.0);
        writeMatrix(&A,0,3,0.0);

        writeMatrix(&A,1,0,9.0);
        writeMatrix(&A,1,1,8.0);
        writeMatrix(&A,1,2,0.0);
        writeMatrix(&A,1,3,8.0);

        writeMatrix(&A,2,0,1.0);
        writeMatrix(&A,2,1,8.0);
        writeMatrix(&A,2,2,5.0);
        writeMatrix(&A,2,3,3.0);

        writeMatrix(&A,3,0,0.0);
        writeMatrix(&A,3,1,0.0);
        writeMatrix(&A,3,2,5.0);
        writeMatrix(&A,3,3,8.0);

        B = matrix(4);

        writeMatrix(&B,0,0,0.0);
        writeMatrix(&B,0,1,9.0);
        writeMatrix(&B,0,2,1.0);
        writeMatrix(&B,0,3,0.0);

        writeMatrix(&B,1,0,9.0);
        writeMatrix(&B,1,1,8.0);
        writeMatrix(&B,1,2,8.0);
        writeMatrix(&B,1,3,0.0);

        writeMatrix(&B,2,0,3.0);
        writeMatrix(&B,2,1,0.0);
        writeMatrix(&B,2,2,5.0);
        writeMatrix(&B,2,3,5.0);

        writeMatrix(&B,3,0,0.0);
        writeMatrix(&B,3,1,8.0);
        writeMatrix(&B,3,2,3.0);
        writeMatrix(&B,3,3,8.0);

	I = identity();
        TEST_MESSAGE("Function matrix transpose");
        TEST_ASSERT_TRUE(isMatrixEqual(B, transpose(A)));
        TEST_ASSERT_TRUE(isMatrixEqual(I,transpose(I)));
}

void test_det2by2()
{
        t_matrix A;
	
	A = matrix(2);
	writeMatrix(&A,0,0,1.0);
        writeMatrix(&A,0,1,5.0);
        writeMatrix(&A,1,0,-3.0);
        writeMatrix(&A,1,1,2.0);
        TEST_MESSAGE("Function determinant 2x2 matrix");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 17, det(A));
	
}

void test_submatrix()
{
	t_matrix A33;
	t_matrix A22;
        t_matrix B44;
        t_matrix B33;

	A33 = matrix(3);
        writeMatrix(&A33,0,0,1.0);
        writeMatrix(&A33,0,1,5.0);
        writeMatrix(&A33,0,2,0.0);

        writeMatrix(&A33,1,0,-3.0);
        writeMatrix(&A33,1,1,2.0);
        writeMatrix(&A33,1,2,7.0);

        writeMatrix(&A33,2,0,0.0);
        writeMatrix(&A33,2,1,6.0);
        writeMatrix(&A33,2,2,-3.0);

        A22 = matrix(2);
        writeMatrix(&A22,0,0,-3.0);
        writeMatrix(&A22,0,1,2.0);
        writeMatrix(&A22,1,0,0.0);
        writeMatrix(&A22,1,1,6.0);

	B44 = matrix(4);
	writeMatrix(&B44,0,0,-6.0);
        writeMatrix(&B44,0,1,1.0);
        writeMatrix(&B44,0,2,1.0);
        writeMatrix(&B44,0,3,6.0);

        writeMatrix(&B44,1,0,-8.0);
        writeMatrix(&B44,1,1,5.0);
        writeMatrix(&B44,1,2,8.0);
        writeMatrix(&B44,1,3,6.0);

        writeMatrix(&B44,2,0,-1.0);
        writeMatrix(&B44,2,1,0.0);
        writeMatrix(&B44,2,2,8.0);
        writeMatrix(&B44,2,3,2.0);

        writeMatrix(&B44,3,0,-7.0);
        writeMatrix(&B44,3,1,1.0);
        writeMatrix(&B44,3,2,-1.0);
        writeMatrix(&B44,3,3,1.0);

	B33 = matrix(3);
        writeMatrix(&B33,0,0,-6.0);
        writeMatrix(&B33,0,1,1.0);
        writeMatrix(&B33,0,2,6.0);

        writeMatrix(&B33,1,0,-8.0);
        writeMatrix(&B33,1,1,8.0);
        writeMatrix(&B33,1,2,6.0);

        writeMatrix(&B33,2,0,-7.0);
        writeMatrix(&B33,2,1,-1.0);
        writeMatrix(&B33,2,2,1.0);	

        TEST_MESSAGE("Function submatrix");
        TEST_ASSERT_TRUE(isMatrixEqual(A22, submatrix(A33,0,2)));
 	TEST_ASSERT_TRUE(isMatrixEqual(B33, submatrix(B44,2,1)));
}

void test_minor()
{
        t_matrix A;

	A = matrix(3);
	writeMatrix(&A,0,0,3.0);
        writeMatrix(&A,0,1,5.0);
        writeMatrix(&A,0,2,0.0);

        writeMatrix(&A,1,0,2.0);
        writeMatrix(&A,1,1,-1.0);
        writeMatrix(&A,1,2,-7.0);

        writeMatrix(&A,2,0,6.0);
        writeMatrix(&A,2,1,-1.0);
        writeMatrix(&A,2,2,5.0);	

	TEST_MESSAGE("Function minor");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 25, minor(A,1,0));
}

void test_cofactor()
{
        t_matrix A;

        A = matrix(3);
        writeMatrix(&A,0,0,3.0);
        writeMatrix(&A,0,1,5.0);
        writeMatrix(&A,0,2,0.0);

        writeMatrix(&A,1,0,2.0);
        writeMatrix(&A,1,1,-1.0);
        writeMatrix(&A,1,2,-7.0);

        writeMatrix(&A,2,0,6.0);
        writeMatrix(&A,2,1,-1.0);
        writeMatrix(&A,2,2,5.0);

        TEST_MESSAGE("Function cofactor");
        TEST_ASSERT_FLOAT_WITHIN(0.01, -12, minor(A,0,0));
        TEST_ASSERT_FLOAT_WITHIN(0.01, -12, cofactor(A,0,0));
        TEST_ASSERT_FLOAT_WITHIN(0.01, 25, minor(A,1,0));
        TEST_ASSERT_FLOAT_WITHIN(0.01, -25, cofactor(A,1,0));


}

void test_det()
{
        t_matrix A;
	t_matrix B;
	float resp;

        A = matrix(3);
	writeMatrix(&A,0,0,1.0);
        writeMatrix(&A,0,1,2.0);
        writeMatrix(&A,0,2,6.0);

        writeMatrix(&A,1,0,-5.0);
        writeMatrix(&A,1,1,8.0);
        writeMatrix(&A,1,2,-4.0);

        writeMatrix(&A,2,0,2.0);
        writeMatrix(&A,2,1,6.0);
        writeMatrix(&A,2,2,4.0);

	B = matrix(4);
        writeMatrix(&B,0,0,-2.0);
        writeMatrix(&B,0,1,-8.0);
        writeMatrix(&B,0,2,3.0);
        writeMatrix(&B,0,3,5.0);

        writeMatrix(&B,1,0,-3.0);
        writeMatrix(&B,1,1,1.0);
        writeMatrix(&B,1,2,7.0);
        writeMatrix(&B,1,3,3.0);

        writeMatrix(&B,2,0,1.0);
        writeMatrix(&B,2,1,2.0);
        writeMatrix(&B,2,2,-9.0);
        writeMatrix(&B,2,3,6.0);

        writeMatrix(&B,3,0,-6.0);
        writeMatrix(&B,3,1,7.0);
        writeMatrix(&B,3,2,7.0);
        writeMatrix(&B,3,3,-9.0);

 
	TEST_MESSAGE("Function determinant 3x3  4x4 matrix");
        TEST_ASSERT_FLOAT_WITHIN(0.01, 56, cofactor(A,0,0));
        TEST_ASSERT_FLOAT_WITHIN(0.01, 12, cofactor(A,0,1));
        TEST_ASSERT_FLOAT_WITHIN(0.01, -46, cofactor(A,0,2));
        TEST_ASSERT_FLOAT_WITHIN(0.01, -196, det(A));

        TEST_ASSERT_FLOAT_WITHIN(0.01, 690, cofactor(B,0,0));
        TEST_ASSERT_FLOAT_WITHIN(0.01, 447, cofactor(B,0,1));
        TEST_ASSERT_FLOAT_WITHIN(0.01, 210, cofactor(B,0,2));
        TEST_ASSERT_FLOAT_WITHIN(0.01, 51, cofactor(B,0,3));
        TEST_ASSERT_FLOAT_WITHIN(0.01, -4071, det(B));
}

void test_isInvertible()
{
        t_matrix A;
        t_matrix B;

        A = matrix(4);
        writeMatrix(&A,0,0,6.0);
        writeMatrix(&A,0,1,4.0);
        writeMatrix(&A,0,2,4.0);
        writeMatrix(&A,0,3,4.0);

        writeMatrix(&A,1,0,5.0);
        writeMatrix(&A,1,1,5.0);
        writeMatrix(&A,1,2,7.0);
        writeMatrix(&A,1,3,6.0);

        writeMatrix(&A,2,0,4.0);
        writeMatrix(&A,2,1,-9.0);
        writeMatrix(&A,2,2,3.0);
        writeMatrix(&A,2,3,-7.0);

        writeMatrix(&A,3,0,9.0);
        writeMatrix(&A,3,1,1.0);
        writeMatrix(&A,3,2,7.0);
        writeMatrix(&A,3,3,-6.0);

        B = matrix(4);
        writeMatrix(&B,0,0,-4.0);
        writeMatrix(&B,0,1,2.0);
        writeMatrix(&B,0,2,-2.0);
        writeMatrix(&B,0,3,-3.0);

        writeMatrix(&B,1,0,9.0);
        writeMatrix(&B,1,1,6.0);
        writeMatrix(&B,1,2,2.0);
        writeMatrix(&B,1,3,6.0);

        writeMatrix(&B,2,0,0.0);
        writeMatrix(&B,2,1,-5.0);
        writeMatrix(&B,2,2,1.0);
        writeMatrix(&B,2,3,-5.0);

        writeMatrix(&B,3,0,0.0);
        writeMatrix(&B,3,1,0.0);
        writeMatrix(&B,3,2,0.0);
        writeMatrix(&B,3,3,0.0);

        TEST_MESSAGE("Function isInvertible");
        TEST_ASSERT_TRUE(isInvertible(A));
        TEST_ASSERT_TRUE(!isInvertible(B));
}

void test_inverse()
{
        t_matrix A;
        t_matrix B;
	t_matrix resp;
	t_matrix C;
        t_matrix D;
	t_matrix AC;
	
        A = matrix(4);
        writeMatrix(&A,0,0,-5.0);
        writeMatrix(&A,0,1,2.0);
        writeMatrix(&A,0,2,6.0);
        writeMatrix(&A,0,3,-8.0);

        writeMatrix(&A,1,0,1.0);
        writeMatrix(&A,1,1,-5.0);
        writeMatrix(&A,1,2,1.0);
        writeMatrix(&A,1,3,8.0);

        writeMatrix(&A,2,0,7.0);
        writeMatrix(&A,2,1,7.0);
        writeMatrix(&A,2,2,-6.0);
        writeMatrix(&A,2,3,-7.0);

        writeMatrix(&A,3,0,1.0);
        writeMatrix(&A,3,1,-3.0);
        writeMatrix(&A,3,2,7.0);
        writeMatrix(&A,3,3,4.0);

        B = matrix(4);
        writeMatrix(&B,0,0,0.21805);
        writeMatrix(&B,0,1,0.45113);
        writeMatrix(&B,0,2,0.24060);
        writeMatrix(&B,0,3,-0.04511);

        writeMatrix(&B,1,0,-0.80827);
        writeMatrix(&B,1,1,-1.45677);
        writeMatrix(&B,1,2,-0.44361);
        writeMatrix(&B,1,3,0.52068);

        writeMatrix(&B,2,0,-0.07895);
        writeMatrix(&B,2,1,-0.22368);
        writeMatrix(&B,2,2,-0.05263);
        writeMatrix(&B,2,3,0.19737);

        writeMatrix(&B,3,0,-0.52256);
        writeMatrix(&B,3,1,-0.81391);
        writeMatrix(&B,3,2,-0.30075);
        writeMatrix(&B,3,3,0.30639);

        C = matrix(4);
        writeMatrix(&C,0,0,8.0);
        writeMatrix(&C,0,1,-5.0);
        writeMatrix(&C,0,2,9.0);
        writeMatrix(&C,0,3,2.0);

        writeMatrix(&C,1,0,7.0);
        writeMatrix(&C,1,1,5.0);
        writeMatrix(&C,1,2,6.0);
        writeMatrix(&C,1,3,1.0);

        writeMatrix(&C,2,0,-6.0);
        writeMatrix(&C,2,1,0.0);
        writeMatrix(&C,2,2,9.0);
        writeMatrix(&C,2,3,6.0);

        writeMatrix(&C,3,0,-3.0);
        writeMatrix(&C,3,1,0.0);
        writeMatrix(&C,3,2,-9.0);
        writeMatrix(&C,3,3,-4.0);

        D = matrix(4);
        writeMatrix(&D,0,0,-0.15385);
        writeMatrix(&D,0,1,-0.15385);
        writeMatrix(&D,0,2,-0.28205);
        writeMatrix(&D,0,3,-0.53846);

        writeMatrix(&D,1,0,-0.07692);
        writeMatrix(&D,1,1,0.12308);
        writeMatrix(&D,1,2,0.02564);
        writeMatrix(&D,1,3,0.03077);

        writeMatrix(&D,2,0,0.35897);
        writeMatrix(&D,2,1,0.35897);
        writeMatrix(&D,2,2,0.43590);
        writeMatrix(&D,2,3,0.92308);

        writeMatrix(&D,3,0,-0.69231);
        writeMatrix(&D,3,1,-0.69231);
        writeMatrix(&D,3,2,-0.76923);
        writeMatrix(&D,3,3,-1.92308);

	resp = inverse(A);
        TEST_MESSAGE("Function inverse");
	TEST_ASSERT_FLOAT_WITHIN(0.01, 532.0, det(A));
	TEST_ASSERT_FLOAT_WITHIN(0.01, -160.0, cofactor(A,2,3));
 	TEST_ASSERT_FLOAT_WITHIN(0.01, -160.0/532.0, resp.element[3][2]);
	TEST_ASSERT_FLOAT_WITHIN(0.01, 105.0, cofactor(A,3,2));
        TEST_ASSERT_FLOAT_WITHIN(0.01, 105.0/532.0, resp.element[2][3]);
	TEST_ASSERT_TRUE(isMatrixEqual(B,resp));
	freeMatrix(resp);
	resp = inverse(C);
 	TEST_ASSERT_TRUE(isMatrixEqual(D,resp));
	freeMatrix(resp);
	AC = matrixMulti(A,C);
	TEST_ASSERT_TRUE(isMatrixEqual(A, matrixMulti(AC,inverse(C))));
}

void test_translation()
{
	t_matrix transform;
	t_tuple p;
	t_tuple p2;
	t_tuple resp;
	t_tuple v;
	t_matrix inv;
	
	transform = translation(5,-3,2); 
	p = point(-3,4,5);
	resp = matrixMultiVec(transform,p);
	p2 = point(2,1,7);
	TEST_MESSAGE("Function translation");
        TEST_ASSERT_TRUE(isEqual(resp, p2));	
	inv = inverse(transform);
	resp  = matrixMultiVec(inv, p);
	p2 = point(-8,7,3); 	
	TEST_ASSERT_TRUE(isEqual(resp, p2));
	v = vector(-3,4,5);
   	resp  = matrixMultiVec(transform, v);
	TEST_ASSERT_TRUE(isEqual(resp, v));	
}

void test_scaling()
{
        t_matrix transform;
        t_tuple p;
        t_tuple p2;
        t_tuple resp;
        t_tuple v;
	t_matrix inv;
	
	transform = scaling(2,3,4);	
	p = point(-4,6,8);	
	resp = matrixMultiVec(transform,p);
        p2 = point(-8,18,32);
        TEST_MESSAGE("Function scaling");
        TEST_ASSERT_TRUE(isEqual(resp, p2));
        v = vector(-4,6,8);
        resp  = matrixMultiVec(transform, v);
	v = vector(-8,18,32);
        TEST_ASSERT_TRUE(isEqual(resp, v));
	inv = inverse(transform);
	v = vector(-4,6,8);	
        resp  = matrixMultiVec(inv, v);
        v = vector(-2,2,2);
        TEST_ASSERT_TRUE(isEqual(resp, v));
	TEST_MESSAGE("Function scaling(reflection)");
	freeMatrix(transform);
	transform = scaling(-1,1,1);
        p = point(2,3,4);
        resp = matrixMultiVec(transform,p);
        p2 = point(-2,3,4);
        TEST_ASSERT_TRUE(isEqual(resp, p2));


}

void test_rotation_x()
{
	t_tuple p;
	t_matrix half_quarter;
	t_matrix full_quarter;	
	t_matrix inv;
	t_tuple resp;;

	p = point(0,1,0);
	half_quarter = rotation_x(M_PI_4);
	full_quarter = rotation_x(M_PI_2);
	resp = matrixMultiVec(half_quarter,p);
	p = point(0,sqrt(2.0)/2.0,sqrt(2.0)/2.0);
	TEST_MESSAGE("Function rotation_x");
        TEST_ASSERT_TRUE(isEqual(resp, p));
 	p = point(0,1,0);
	resp = matrixMultiVec(full_quarter,p);
	p = point(0,0,1);
	TEST_ASSERT_TRUE(isEqual(resp, p));
 	p = point(0,1,0);
	inv = inverse(half_quarter);	
	resp = matrixMultiVec(inv,p);
	p = point(0,sqrt(2.0)/2.0,-sqrt(2.0)/2.0);
	TEST_ASSERT_TRUE(isEqual(resp, p));
}

void test_rotation_y()
{
        t_tuple p;
        t_matrix half_quarter;
        t_matrix full_quarter;
        t_matrix inv;
        t_tuple resp;;

        p = point(0,0,1);
        half_quarter = rotation_y(M_PI_4);
        full_quarter = rotation_y(M_PI_2);
        resp = matrixMultiVec(half_quarter,p);
        p = point(sqrt(2.0)/2.0,0,sqrt(2.0)/2.0);
        TEST_MESSAGE("Function rotation_y");
        TEST_ASSERT_TRUE(isEqual(resp, p));
        p = point(0,0,1);
        resp = matrixMultiVec(full_quarter,p);
        p = point(1,0,0);
        TEST_ASSERT_TRUE(isEqual(resp, p));
}

void test_rotation_z()
{
        t_tuple p;
        t_matrix half_quarter;
        t_matrix full_quarter;
        t_matrix inv;
        t_tuple resp;;

        p = point(0,1,0);
        half_quarter = rotation_z(M_PI_4);
        full_quarter = rotation_z(M_PI_2);
        resp = matrixMultiVec(half_quarter,p);
        p = point(-sqrt(2.0)/2.0,sqrt(2.0)/2.0,0);
        TEST_MESSAGE("Function rotation_y");
        TEST_ASSERT_TRUE(isEqual(resp, p));
        p = point(0,1,0);
        resp = matrixMultiVec(full_quarter,p);
        p = point(-1,0,0);
        TEST_ASSERT_TRUE(isEqual(resp, p));
}

void test_shearing()
{
	t_matrix transform;
	t_tuple p;
	t_tuple resp;

	transform = shearing(1,0,0,0,0,0);	
	p = point(2,3,4);
	resp = matrixMultiVec(transform,p);
	p = point(5,3,4);
	TEST_MESSAGE("Function shearing");
        TEST_ASSERT_TRUE(isEqual(resp, p));

	transform = shearing(0,1,0,0,0,0);
        p = point(2,3,4);
        resp = matrixMultiVec(transform,p);
        p = point(6,3,4);
	TEST_ASSERT_TRUE(isEqual(resp, p));

        transform = shearing(0,0,1,0,0,0);
        p = point(2,3,4);
        resp = matrixMultiVec(transform,p);
        p = point(2,5,4);
        TEST_ASSERT_TRUE(isEqual(resp, p));

        transform = shearing(0,0,0,1,0,0);
        p = point(2,3,4);
        resp = matrixMultiVec(transform,p);
        p = point(2,7,4);
        TEST_ASSERT_TRUE(isEqual(resp, p));

        transform = shearing(0,0,0,0,1,0);
        p = point(2,3,4);
        resp = matrixMultiVec(transform,p);
        p = point(2,3,6);
        TEST_ASSERT_TRUE(isEqual(resp, p));

        transform = shearing(0,0,0,0,0,1);
        p = point(2,3,4);
        resp = matrixMultiVec(transform,p);
        p = point(2,3,7);
        TEST_ASSERT_TRUE(isEqual(resp, p));
}

void test_transformation()
{
	t_tuple p;
	t_tuple p2;
	t_tuple p3;
	t_tuple p4;
	t_matrix A;
	t_matrix B;
	t_matrix C;
	t_tuple T;

	A = rotation_x(M_PI_2);
	B = scaling(5,5,5);
	C = translation(10,5,7);
	
        TEST_MESSAGE("Transformations");
        
	p = point(1,0,1);
	p2 = matrixMultiVec(A,p);
	p = point(1,-1,0);
	TEST_ASSERT_TRUE(isEqual(p2, p));
	
        p3 = matrixMultiVec(B,p2);
        p = point(5,-5,0);
        TEST_ASSERT_TRUE(isEqual(p3, p));

        p4 = matrixMultiVec(C,p3);
        p = point(15,0,7);
        TEST_ASSERT_TRUE(isEqual(p4, p));

        p = point(1,0,1);
	T = matrixMultiVec(matrixMulti(C,matrixMulti(B,A)),p);
        p = point(15,0,7);
        TEST_ASSERT_TRUE(isEqual(T, p));
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
	RUN_TEST(test_matrix);
	RUN_TEST(test_isMatrixEqual);
	RUN_TEST(test_matrixMulti);	
	RUN_TEST(test_matrixMultiVec);
	RUN_TEST(test_matrixIdenty);
	RUN_TEST(test_matrixTranspose);
	RUN_TEST(test_det2by2);
	RUN_TEST(test_submatrix);
	RUN_TEST(test_minor);
	RUN_TEST(test_cofactor);
	RUN_TEST(test_det);
	RUN_TEST(test_isInvertible);
	RUN_TEST(test_inverse);
	RUN_TEST(test_translation);
	RUN_TEST(test_scaling);
	RUN_TEST(test_rotation_x);
	RUN_TEST(test_rotation_y);
	RUN_TEST(test_rotation_z);
	RUN_TEST(test_shearing);
	RUN_TEST(test_transformation);
	return UNITY_END();
}
