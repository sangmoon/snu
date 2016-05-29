/*
name : parksangmoon
loginID : sp29
student ID : 2010-12343
*/

/*
*  캐시 스트럭트는 셋의 주소를 가지고 있습니다. 그리고 셋마다 라인을 할당하여서 접근하게 됩니다.
*  라인은 valid bit 와 tag, age bit를 가지고 있습니다. age_bit는 lru를 구현할 때 사용합니다.
*  
*  메인 합수는 5개의 함수로 구성되어 있습니다.
*  parse_arg에서는 인자로 넘겨준 값들을 받아내고,
*  make_cache 함수를 통해 인자에 맞는 크기의 캐쉬를 만듭니다.
*  caching 함수에서 텍스트 파일의 데이터를 가져와 캐시 작업을 진행하고
*  printSummary 함수에서 결과를 리턴합니다.
*  마지막으로 delete_cache에서 mallocd으로 할당한 메모리를 반납합니다.
*/


#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
typedef unsigned int uint32;
char temp;
char *vervo[2];
char* trace_file = NULL; 
uint32 v=0;
uint32 s=0;
uint32 E=0;
uint32 b=0;

uint32 log2_t(uint32 a, uint32 i)
{
	return (a == 1 ? i:log2_t(a>>1,i+1));
}

// line
typedef struct _line
{
	uint32 valid; 
	uint32 tag;
	uint32 age_bit; //for lru
} Line;

//set
typedef struct _set
{
	Line *way;
	uint32 num_of_lines; //# of lines to have vaild bit
} Set;
//cache
typedef struct _cache
{
	Set *set;
	uint32 num_of_hit;
	uint32 num_of_miss;
	uint32 num_of_evict;

	uint32 ways;
	uint32 sets;
	uint32 tag_shift;
} Cache;

Cache* make_cache()
{
	int i=0;

	Cache* C=(Cache*)calloc(1,sizeof(Cache));
	C->ways=E;
	C->sets=(uint32)pow(2,s);
	C->tag_shift = s+b;

	Set* S = (Set*)calloc(C->sets,sizeof(Set));
	C->set = S;

	for(i=0;i<C->sets;i++)
	{
		Line *L = (Line*)calloc(C->ways,sizeof(Line));
		(S+i)->way = L;
	}
	/*printf("Cache configuration:\n"
		"Sets : %6u\n"
		"Ways : %6u\n"
		"tag_shift : %6u\n"
		, C->sets,C->ways,C->tag_shift);
	*/
	return C;
}

void delete_cache(Cache* c)
{
	int idx;
	int set= c->sets;

	for (idx = 0; idx<set;idx++)
	{
		free(((c->set)+idx)->way);
	}
	free(c->set);
	
	free(c);
}

void caching(Cache* c,char* trace)
{
	char buffer[1500];
	unsigned long long int addr=0;
	uint32 len=0;
	uint32 line_mask=0;
	uint32 set_mask=0;
	uint32 tag_mask=0;
	uint32 set_index=0;
	uint32 tag=0;
	int num_of_iter=0;
	int i=0;
	int j=0;
	uint32 line_idx=0;
	int is_hit =0;
	uint32 empty_line_idx=0;
	uint32 is_full = 0;
	uint32 num_of_evict_line=0;


	FILE* trace_f = fopen(trace,"r");
	if(!trace_f)
	{
		printf("file open error!\n");
		exit(1);
	}
	
	line_mask=pow(2,b) -1;
	set_mask=pow(2,s) - 1;
	set_mask<<=(b);

	tag_mask=~(set_mask|line_mask);
	
	while(fgets(buffer,1500,trace_f)!=NULL)
	{
		sscanf(buffer+3, "%llx,%u", &addr,&len);
		if(buffer[1]==' ')
		{	
			continue;
		}
		//printf("%c\n",buffer[1]);
		//if(v)
			//printf("%c %llx, %u\n",buffer[1], addr, len);
		tag= (tag_mask&addr) >> (c->tag_shift);
		set_index= (set_mask&addr) >> (b);
		num_of_iter = 1;
		line_idx=0;
		empty_line_idx=0;
		vervo[0]=NULL;
		vervo[1]=NULL;
		if (buffer[1]=='M')
		{
			num_of_iter=2;
		}
		for (j=0;j<num_of_iter;j++)
		{
			is_hit=0;
			is_full=1;
			num_of_evict_line=0;
			
			for(line_idx=0;line_idx < c->ways;line_idx++)
			{
				if(((((c->set)+set_index)->way)+line_idx)->valid)
				{
					if(((((c->set)+set_index)->way)+line_idx)->tag==tag)
					{
						(c->num_of_hit)++; //valid and tag OK!
						is_hit = 1;
						
						for (i=0; i< c->ways;i++)
						{
							if(((((c->set)+set_index)->way)+i)->valid)
							{
								(((((c->set)+set_index)->way)+i)->age_bit)++;
							}
						}
						(((((c->set)+set_index)->way)+line_idx)->age_bit)=0;
						if(buffer[1]=='M' && j==1)
							vervo[1]="hit";
						else
							vervo[0]="hit";
						break;
					}
							
				}
				else // none valid line is found
				{
					empty_line_idx=line_idx;
					is_full=0;
				}
			}
			if(!is_hit) //miss! check whether there is space for new cache!
			{
				c->num_of_miss++;

				if(!is_full) // empty_line_idx exist!
				{
					(((((c->set)+set_index)->way)+empty_line_idx)->valid)=1;
					(((((c->set)+set_index)->way)+empty_line_idx)->tag)=tag;
                                        for (i=0; i< c->ways;i++)
                                        {
                                        	if(((((c->set)+set_index)->way)+i)->valid)
                                        	{
                                                	(((((c->set)+set_index)->way)+i)->age_bit)++;
                                                }
                                        }
                                        (((((c->set)+set_index)->way)+empty_line_idx)->age_bit)=0;
					vervo[0]="miss";					
				}
				
				else // we need evict by lru!
				{
					c->num_of_evict++;
					for (i=1; i< c->ways;i++)
					{
						if (((((c->set)+set_index)->way)+num_of_evict_line)->age_bit < ((((c->set)+set_index)->way)+i)->age_bit)
							num_of_evict_line = i;				
					}
					((((c->set)+set_index)->way)+num_of_evict_line)->tag = tag;
                                        for (i=0; i< c->ways;i++)
                                        {
                                                if(((((c->set)+set_index)->way)+i)->valid)
                                                {
                                                        (((((c->set)+set_index)->way)+i)->age_bit)++;
                                                }
                                        }
                                        (((((c->set)+set_index)->way)+num_of_evict_line)->age_bit)=0;
					vervo[0]="miss evict";								
				}
			}
		}
		//temp=buffer[1];
		if(v) // verbosity result print.
		{
			printf("%c %llx, %u, %s, %s\n",buffer[1], addr, len,vervo[0],vervo[1]);
		}	
	}
	fclose(trace_f);	
	return;
}

void parse_arg(int argc, char *argv[])
{
	char flag;
	while((flag=getopt(argc,argv,"vs:E:b:t:")) != -1)
	{
		switch(flag)
		{
		case 'v':
			v = 1;
			break;
		case 's':
			s=atoi(optarg);
			break;
		case 'E':
			E = atoi(optarg);
			break;
		case 'b':
			b = atoi(optarg);
			break;
		case 't':
			trace_file = optarg;
			break;
		
		default:
			printf("nonono it's default!\n");
			exit(1);
		}
	}
}

int main(int argc,char *argv[])
{
	parse_arg(argc,argv);
	Cache* C = make_cache();
	caching(C,trace_file);
	printSummary(C->num_of_hit,C->num_of_miss,C->num_of_evict);
	delete_cache(C);
	return 0;
}
