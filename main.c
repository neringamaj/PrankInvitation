#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define start "Please enter the following information: \n"
#define enter_name "Name: "
#define enter_surname "Surname: "
#define enter_picture "Name of your picture (please upload it into the same folder): "
#define enter_car "If you will come to the party by car (yes or no): "
#define enter_lift "If you could give a lift to those without a car (yes or no): "
#define enter_plus1 "If you will bring a +1 (yes or no): "
#define enter_stay "Will you stay the night (yes or no): "

void file(char name[], char surname[]);
int prize_car(char lift[]);
void print(char name[], char surname[], char picture[], char car[], char lift[], char plus1[], char night[], int prize);
void participant_list(char name[], char surname[], char picture[], char car[], char lift[], char plus1[], char night[], int prize);
void list_print();
void new_char(FILE* fl, char name[], char surname[], char picture[], char car[], char lift[], char plus1[], char night[], int prize);
void new_participant(char name[], char surname[], char picture[], char car[], char lift[], char plus1[], char night[], int prize);

int main(){
    char name[50] = "", surname[50] = "", picture[50] = "", car[4] = "", lift[4] = "", plus1[4] = "", night[4] = "", new_line;

    printf(start);
    printf(enter_name);
    scanf("%50s", &name);
    printf(enter_surname);
    scanf("%50s", &surname);
    printf(enter_picture);
    scanf("%50s", &picture);
    printf(enter_car);
    scanf("%4s", &car);
    printf(enter_lift);
    scanf("%4s", &lift);
    printf(enter_plus1);
    scanf("%4s", &plus1);
    printf(enter_stay);
    scanf("%4s", &night);

    int prize = prize_car(lift);
    file(name, surname);
    print(name, surname, picture, car, lift, plus1, night, prize);


    return 0;
}
int prize_car(char lift[]){
    if(lift[0] == 'Y' || lift[0] == 'y')
        if(lift[1] == 'E' || lift[1] == 'e')
            if(lift[2] == 'S' || lift[2] == 's')
                return 1;
    else return 0;
}
void file(char name[], char surname[]) {
    FILE *fr;
    fr = fopen("list.txt", "a");

    if (fr == NULL)
        perror("Can not open list of participants.\n");
    else {
        fprintf(fr, "%s ", name);
        fprintf(fr, "%s\n", surname);
    }
    fclose(fr);
}
void list_print(){
    FILE * li;
    li = fopen("list.txt", "r");
    char just[60];
    while(!feof(li)){
        fscanf(li, "%s", just);
        printf("<li>%s</li>\n",just);
    }
}
void print(char name[], char surname[], char picture[], char car[], char lift[], char plus1[], char night[], int prize){
    //html file
    FILE *html;
    html = freopen("index.html", "w", stdout);
    printf("\
<html>\
<head>\
<style>\n\
	body{\n\
		background-color: black;\n\
		font-family: \"Time New Roman\";\n\
	}\n\
	#list{\n\
		height: 100%%;\n\
		width: 100%%;\n\
	}\n\
	.img_gen{\n\
		height: 90%%;\n\
		width: 30%%;\n\
		background-image: url(\"https://images.unsplash.com/photo-1545505567-7327366a634d?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxleHBsb3JlLWZlZWR8NXx8fGVufDB8fHx8&w=1000&q=80\");\n\
		background-repeat: no-repeat;\n\
		background-size: contain;\n\
		float: left;\n\
	}\n\
	.img_right{\n\
		float: right;\n\
		background-position: right;\n\
	}\n\
	.user{\n\
		height: 90%%;\n\
		width: 40%%;\n\
		color: white;\n\
		text-align: center;\n\
		float: left;\n\
	}\n\
	.img_user{\n\
		height: 40%%;\n\
		width: 100%%;\n\
		background-image: url(\"%s\");\n\
		background-position: center;\n\
		background-repeat: no-repeat;\n\
		background-size: contain;\n\
	}\n\
	.user_btn{\n\
		height: 30%%;\n\
		width: 50%%;\n\
		position: absolute;\n\
		bottom:0;\n\
		left:25%%;\n\
		border: 2px solid orange;\n\
		background-color: transparent;\n\
		font-family: \"Time New Roman\";\n\
		font-size: 25;\n\
		color:white;\n\
		text-decoration: none;\n\
	}\n\
	.user_btn:hover{\n\
		transition: 2s;\n\
		border: none;\n\
		background-image: url(\"https://cdn.crello.com/api/media/medium/470791980/stock-vector-arrow-pointing-right-yellow-glowing?token=\");\n\
		background-position: center;\n\
		background-repeat: no-repeat;\n\
		background-size: cover;\n\
		color: rgba(0,0,0,0);\n\
	}\n\
    .d{\n\
		width: 100%%;\n\
		height: 10%%;\n\
		float: left;\n\
		text-align: center;\n\
	}\n\
	.list_btn{\n\
		border: 2px solid orange;\n\
		background-color: transparent;\n\
		height:80%%;\n\
		width: 30%%;\n\
		font-size: 25;\n\
		color: white;\n\
		font-family: \"Time New Roman\";\n\
	}\n\
	.preview_btn{\n\
		height:10%%;\n\
	}\n\
	.sup{\n\
		height: 100%%;\n\
		width: 100%%;\n\
	}\n\
	.img_sup{\n\
		height: 100%%;\n\
		width: 100%%;\n\
		background-image: url(\"%s\");\n\
		background-repeat: no-repeat;\n\
		background-size: cover;\n\
		background-position: center;\n\
	}\n\
	.txt_sup{\n\
		background-color: rgb(0,0,0,0.7);\n\
		width: 50%%;\n\
		height: 50%%;\n\
		left: 25%%;\n\
		top: 25%%;\n\
		position: absolute;\n\
		text-align: center;\n\
		color: yellow;\n\
		font-size: 30;\n\
	}\n\
	.arr_sup{\n\
		width: 10%%;\n\
		height : 40%%;\n\
		position: absolute;\n\
		opacity:0.75;\n\
		background-image: url(\"https://media.istockphoto.com/videos/down-arrow-glowing-symbol-outline-looping-on-black-background-video-id1201183894?s=640x640\");\n\
		background-repeat: no-repeat;\n\
		background-position: center;\n\
		background-size: cover;\n\
		box-shadow: 0 0 5px 10px rgb(0,0,0);\n\
		border-radius: 50%%;\n\
	}\n\
	.arr1{\n\
		left: 32%%;\n\
	}\n\
	.arr2{\n\
		left: 45%%;\m\
    }\n\
	.arr3{\n\
		left: 58%%;\n\
	}\n\
	.btn_sup{\n\
		color: rgb(90, 7, 90);\n\
		margin-top: 16%%;\n\
		border: 3px solid yellow;\n\
		background-color: rgb(148, 0, 0);\n\
		width: 50%%;\n\
		height: 20%%;\n\
		text-shadow: -1px -1px 0 yellow, 1px -1px 0 yellow, -1px 1px 0 yellow, 1px 1px 0 yellow;\n\
		font-size: 25;\n\
	}\n\
</style>\n\
<script>\n\
	function show(shown, hidden) {\n\
		document.getElementById(shown).style.display='block';\n\
		document.getElementById(hidden).style.display='none';\n\
		return false;\n\
	}\n\
</script>\n\
</head>\n\
<body>\n\
	<div id = 'list' style = 'display: none;color:white;'>\n\
		<div style = \"text-align: center;\"><a href = '#' onclick = \"return show('index', 'list');\"><button class = 'list_btn preview_btn'>Atgal į paskutinio įvesto pakvietimą</button></a></div>\n\
		<div style = \"width:20%%;height:90%%;float:left\"></div>\n\
		<div style = \"float:left\">\n\
			<ul style = 'text-align: left;'>\n",picture,prize == 1 ? "https://www.lamborghini.com/sites/it-en/files/DAM/lamborghini/facelift_2019/model_gw/aventador/2021/gate_aven_s_01_m.jpg" : "https://historyfangirl.com/wp-content/uploads/2020/06/shutterstock_1090496174.jpg");
            list_print();
			printf("</ul>\n\
\
		</div>\n\
	</div>\n\
	<div class = 'gen' id = 'index'>\n\
		<div class = 'd'>\n\
			<a href = '#' onclick = \"return show('list', 'index');\"><button class = 'list_btn'>Visų įvestų dalyvių sąrašas</button><a>\n\
		</div>\n\
		<div class = 'img_gen'></div>\n\
		<div class = 'user'>\n\
			<div class = 'img_user'></div>\n\
			<div style = 'position:relative;height:50%%;'>\n\
				<h1>New Year's party!</h1>\n\
				<p>We are very happy to invite %s %s to the best ever New Years party!</p>\n\
				<br>\n\
				<ul style = 'text-align: left;''>\n\
					<li>By car?%s</li>\n\
					<li>Will give a lift?%s</li>\n\
					<li>+1?%s</li>\n\
					<li>Stay the night?%s</li>\n\
				</ul>\n\
				<a href = '#' onclick = \"return show('suprise', 'index');\"><button class = 'user_btn'>Everything is right!</button></a>\n\
			</div>\n\
		</div>\n\
		<div class = 'img_gen img_right'></div>\n\
	</div>\n\
	<div class = 'sup' id = 'suprise' style = 'display: none;'>\n\
		<div class = 'img_sup'>\n\
			<div class = 'txt_sup'>\n\
				<p>Congratulation %s!!!!!! You won a %s. To reclaim your prize</p>\n\
				<div class = 'arr_sup arr1'></div>\n\
				<div class = 'arr_sup arr2'></div>\n\
				<div class = 'arr_sup arr3'></div>\n\
				<br>\n\
				<a href = 'https://youtu.be/dQw4w9WgXcQ?t=43'><button class = 'btn_sup'>CLINK HERE!</button></a>\n\
			</div>\n\
		</div>\n\
    </div>\n\
</body>\n\
</html>\
    ", name, surname,car,lift,plus1,night,name, prize == 1 ? "car" : "vacation");
}

