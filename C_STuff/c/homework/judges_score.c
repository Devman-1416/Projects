// Devin Combs
#include <stdio.h>
float get_score ();
float get_low(float s1, float s2, float s3, float s4);
float get_high(float s1, float s2, float s3, float s4);
float get_final(float s1, float s2 ,float s3, float s4, float hs, float ls);
void display_scores(float s1, float s2, float s3, float s4, float fs);
int main ( ){

	// Get Input
	float score1 = get_score();
	float score2 = get_score();
	float score3 = get_score();
	float score4 = get_score();

	// Calc Low and High Scores
	float low_score = get_low(score1,score2,score3,score4);
	float high_score = get_high(score1,score2,score3,score4);

	// Get Final Score
	float final_score = get_final(score1,score2,score3,score4,high_score,low_score);

	//Display Results
	display_scores(score1,score2,score3,score4,final_score);


	return 0;
}

float get_score (){
	float s;
	
	printf("Enter a Score: ");
	scanf("%f",&s);
	
	return s;
}

float get_high(float s1, float s2, float s3, float s4){
	float ls;
	
	if (s1 > s2 && s1 > s3 && s1 > s4) ls = s1;
		
	else if (s2 > s3 && s2 > s4) ls = s2;
	
	else if (s3 > s4) ls = s3;
	
	else ls = s4;
	
	return ls;
}

float get_low(float s1, float s2, float s3, float s4){
	float hs;
	
	if (s1 < s2 && s1 < s3 && s1 < s4) hs = s1;
		
	else if (s2 < s3 && s2 < s4) hs = s2;
	
	else if (s3 < s4) hs = s3;
	
	else hs = s4;
	
	return hs;
}

float get_final(float s1, float s2, float s3, float s4, float hs, float ls){
	float sum = s1+s2+s3+s4;
	float fs = (sum - (hs+ls)) / 2;
	return fs;
}

void display_scores(float s1, float s2, float s3, float s4, float fs){
	printf("\nScore 1:     %.1f",s1);
	printf("\nScore 2:     %.1f",s2);
	printf("\nScore 3:     %.1f",s3);
	printf("\nScore 4:     %.1f",s4);
	printf("\nFinal Score: %.1f",fs);
}
