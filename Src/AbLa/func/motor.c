#include"motor.h"
#include "tim.h"
#include"gpio.h"

void motorlinks (grad,stby,stop){
	const uint16_t PWM = 560; //(Duty-cycle = 35%)  Strom und Spannungsbegrenzung für den Motor sollte nicht geändert werden, da sonst der Motor kaputt geht und, wenn nur unter genauer Beobachtung
	 int8_t currentstep = 0;
	 uint8_t start = 0;
	 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);

	  /* Infinite loop */
	  /* USER CODE BEGIN WHILE */

	 while (1) {
	   if (stby && start) {
	     GPIOA->BSRR = motor_stby_Pin;

	     if (stop == 0) {
	       if (grad == 0) {
	         // Bremse aktivieren
	         GPIOB->BSRR = motor_la2_Pin;
	         GPIOB->BSRR = motor_lb2_Pin;
	         GPIOA->BSRR = motor_la1_Pin;
	         GPIOB->BSRR = motor_lb1_Pin;
	         TIM2->CCR4 = 0;
	       } if(grad>0){

	       step = (int16_t)((grad / 1.8) + 0.5);}
	       else {
	    	   step = (int16_t)(-1*((grad / 1.8) + 0.5));
	       }

	        if (grad > 0  && step != 0) {

	         while (step > 0) {

	        	 if (currentstep % 4 == 0){
	    // Schritt 1
	        		 TIM2->CCR4 = PWM;
	           GPIOA->BRR = motor_la1_Pin;
	           GPIOB->BSRR = motor_la2_Pin;
	           GPIOB->BRR = motor_lb2_Pin;
	           GPIOB->BRR = motor_lb1_Pin;
	           currentstep++;
	           step--;

	           if (step == 0) break;
	        	 }
	        	 if(currentstep % 4 == 1){
	           // Schritt 2
	        		 TIM2->CCR4 = PWM;
	           GPIOB->BSRR = motor_lb2_Pin;
	           GPIOB->BRR = motor_lb1_Pin;
	           GPIOA->BRR = motor_la1_Pin;
	           GPIOB->BRR = motor_la2_Pin;
	           currentstep++;
	           step--;
	           if (step == 0) break;
	        	 }
	           if (currentstep % 4 == 2){
	           // Schritt 3
	        		 TIM2->CCR4 = PWM;
	           GPIOA->BSRR = motor_la1_Pin;
	           GPIOB->BRR = motor_la2_Pin;
	           GPIOB->BRR = motor_lb2_Pin;
	           GPIOB->BRR = motor_lb1_Pin;
	           currentstep++;
	           step--;
	           if (step == 0) break;
	        	 }
	        	if (currentstep % 4 == 3){
	           // Schritt 4
	        		 TIM2->CCR4 = PWM;
	           GPIOB->BRR = motor_lb2_Pin;
	           GPIOB->BSRR = motor_lb1_Pin;
	           GPIOA->BRR = motor_la1_Pin;
	           GPIOB->BRR = motor_la2_Pin;
	           currentstep++;
	           step--;
	           if (step == 0) break;
	        	 }
	         }
	       }
	         if (grad < 0 && step !=0) {


	                while (step > 0) {
	                	 if (currentstep % 4 == 0 ){
	                  // Schritt 1
	                		 TIM2->CCR4 = PWM;
	                  GPIOA->BSRR = motor_la1_Pin;
	                  GPIOB->BRR = motor_la2_Pin;
	                  GPIOB->BRR = motor_lb2_Pin;
	                  GPIOB->BRR = motor_lb1_Pin;
	                  currentstep--;
	                  step--;
	                  if (step == 0) break;}

	                  if (currentstep % 4 == 1 ){

	                  // Schritt 2
	                	  TIM2->CCR4 = PWM;
	                  GPIOB->BRR = motor_lb2_Pin;
	                  GPIOB->BSRR = motor_lb1_Pin;
	                  GPIOA->BRR = motor_la1_Pin;
	                  GPIOB->BRR = motor_la2_Pin;
	                  currentstep--;
	                  step--;
	                  if (step == 0) break;}

	                  else if (currentstep % 4 == 2){
	                  // Schritt 3
	                	  TIM2->CCR4 = PWM;
	                  GPIOA->BRR = motor_la1_Pin;
	                  GPIOB->BSRR = motor_la2_Pin;
	                  GPIOB->BRR = motor_lb2_Pin;
	                  GPIOB->BRR = motor_lb1_Pin;
	                  currentstep--;
	                  step--;
	                  if (step == 0) break;
	                  }
	                  else if (currentstep % 4 == 3){
	                  // Schritt 4
	                	  TIM2->CCR4 = PWM;
	                  GPIOB->BSRR = motor_lb2_Pin;
	                  GPIOB->BRR = motor_lb1_Pin;
	                  GPIOA->BRR = motor_la1_Pin;
	                  GPIOB->BRR = motor_la2_Pin;
	                  currentstep--;
	                  step--;
	                  if (step == 0) break;}
	                }
	              }
	     } else {
	       // Stoppmodus
	    	 TIM2->CCR4 = PWM;
	       GPIOB->BRR = motor_lb2_Pin;
	       GPIOB->BRR = motor_lb1_Pin;
	       GPIOA->BRR = motor_la1_Pin;
	       GPIOB->BRR = motor_la2_Pin;

	     }
	   } else  if (stby==0){
	     // Initialisierungssequenz
	     TIM2->CCR4 = PWM;

	     GPIOA->BRR = motor_la1_Pin;
	     GPIOB->BSRR = motor_la2_Pin;
	     GPIOB->BRR = motor_lb2_Pin;
	     GPIOB->BRR = motor_lb1_Pin;

	     GPIOB->BSRR = motor_lb2_Pin;
	     GPIOB->BRR = motor_lb1_Pin;
	     GPIOA->BRR = motor_la1_Pin;
	     GPIOB->BRR = motor_la2_Pin;

	     GPIOA->BSRR = motor_la1_Pin;
	     GPIOB->BRR = motor_la2_Pin;
	     GPIOB->BRR = motor_lb2_Pin;
	     GPIOB->BRR = motor_lb1_Pin;

	     GPIOB->BRR = motor_lb2_Pin;
	     GPIOB->BSRR = motor_lb1_Pin;
	     GPIOA->BRR = motor_la1_Pin;
	     GPIOB->BRR = motor_la2_Pin;

	     TIM2->CCR4 = 0;
	     start = 0;
	     currentstep = 0;
	     GPIOA->BRR = motor_stby_Pin;
	     HAL_Delay(1);
	   } else if (start==0){
		   TIM2->CCR4 = PWM;

		        GPIOA->BRR = motor_la1_Pin;
		        GPIOB->BSRR = motor_la2_Pin;
		        GPIOB->BRR = motor_lb2_Pin;
		        GPIOB->BRR = motor_lb1_Pin;

		        GPIOB->BSRR = motor_lb2_Pin;
		        GPIOB->BRR = motor_lb1_Pin;
		        GPIOA->BRR = motor_la1_Pin;
		        GPIOB->BRR = motor_la2_Pin;

		        GPIOA->BSRR = motor_la1_Pin;
		        GPIOB->BRR = motor_la2_Pin;
		        GPIOB->BRR = motor_lb2_Pin;
		        GPIOB->BRR = motor_lb1_Pin;

		        GPIOB->BRR = motor_lb2_Pin;
		        GPIOB->BSRR = motor_lb1_Pin;
		        GPIOA->BRR = motor_la1_Pin;
		        GPIOB->BRR = motor_la2_Pin;

		        TIM2->CCR4 = 0;
		        start = 1;
		        currentstep = 0;
	   }

}

	 void motorrechts (grad,stby,stop){
		 const uint16_t PWM = 560; //(Duty-cycle = 35%)  Strom und Spannungsbegrenzung für den Motor sollte nicht geändert werden, da sonst der Motor kaputt geht und, wenn nur unter genauer Beobachtung
		 	 int8_t currentstepr = 0;
		 	 uint8_t startr = 0;
		 	 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
		 	 while (1){
		 		if (stbyr && startr) {
		 		     GPIOA->BSRR = motor_stby_Pin;

		 		     if (stopr == 0) {
		 		       if (gradr == 0) {
		 		         // Bremse aktivieren
		 		         GPIOA->BSRR = motor_ra2_Pin;
		 		         GPIOA->BSRR = motor_rb2_Pin;
		 		         GPIOC->BSRR = motor_ra1_Pin;
		 		         GPIOA->BSRR = motor_rb1_Pin;
		 		         TIM2->CCR4 = 0;
		 		       } if(gradr>0){

		 		       step = (int16_t)((gradr / 1.8) + 0.5);}
		 		       else {
		 		    	   step = (int16_t)(-1*((gradr / 1.8) + 0.5));
		 		       }

		 		        if (gradr > 0  && stepr != 0) {

		 		         while (stepr > 0) {

		 		        	 if (currentstepr % 4 == 0){
		 		    // Schritt 1
		 		        		 TIM2->CCR4 = PWMr;
		 		           GPIOC->BRR = motor_ra1_Pin;
		 		           GPIOA->BSRR = motor_ra2_Pin;
		 		           GPIOA->BRR = motor_rb2_Pin;
		 		           GPIOA->BRR = motor_rb1_Pin;
		 		           currentstepr++;
		 		           stepr--;

		 		           if (stepr == 0) break;
		 		        	 }
		 		        	 if(currentstepr % 4 == 1){
		 		           // Schritt 2
		 		        	TIM2->CCR4 = PWMr;
		 		           GPIOA->BSRR = motor_rb2_Pin;
		 		           GPIOA->BRR = motor_rb1_Pin;
		 		           GPIOC->BRR = motor_ra1_Pin;
		 		           GPIOA->BRR = motor_ra2_Pin;
		 		           currentstepr++;
		 		           stepr--;
		 		           if (stepr == 0) break;
		 		        	 }
		 		           if (currentstepr % 4 == 2){
		 		           // Schritt 3
		 		        		 TIM2->CCR4 = PWMr;
		 		           GPIOC->BSRR = motor_ra1_Pin;
		 		           GPIOA->BRR = motor_ra2_Pin;
		 		           GPIOA->BRR = motor_rb2_Pin;
		 		           GPIOA->BRR = motor_rb1_Pin;
		 		           currentstepr++;
		 		           stepr--;
		 		           if (stepr == 0) break;
		 		        	 }
		 		        	if (currentstepr % 4 == 3){
		 		           // Schritt 4
		 		        		 TIM2->CCR4 = PWMr;
		 		           GPIOA->BRR = motor_rb2_Pin;
		 		           GPIOA->BSRR = motor_rb1_Pin;
		 		           GPIOC->BRR = motor_ra1_Pin;
		 		           GPIOA->BRR = motor_ra2_Pin;
		 		           currentstepr++;
		 		           stepr--;
		 		           if (stepr == 0) break;
		 		        	 }
		 		         }
		 		       }
		 		         if (gradr < 0 && stepr !=0) {


		 		                while (stepr > 0) {
		 		                	 if (currentstepr % 4 == 0 ){
		 		                  // Schritt 1
		 		                		 TIM2->CCR4 = PWMr;
		 		                  GPIOC->BSRR = motor_ra1_Pin;
		 		                  GPIOA->BRR = motor_ra2_Pin;
		 		                  GPIOA->BRR = motor_rb2_Pin;
		 		                  GPIOA->BRR = motor_rb1_Pin;
		 		                  currentstepr--;
		 		                  stepr--;
		 		                  if (stepr == 0) break;}

		 		                  if (currentstepr % 4 == 1 ){

		 		                  // Schritt 2
		 		                	  TIM2->CCR4 = PWMr;
		 		                  GPIOA->BRR = motor_rb2_Pin;
		 		                  GPIOA->BSRR = motor_rb1_Pin;
		 		                  GPIOC->BRR = motor_ra1_Pin;
		 		                  GPIOA->BRR = motor_ra2_Pin;
		 		                  currentstep--;
		 		                  step--;
		 		                  if (step == 0) break;}

		 		                  else if (currentstep % 4 == 2){
		 		                  // Schritt 3
		 		                	  TIM2->CCR4 = PWM;
		 		                  GPIOC->BRR = motor_ra1_Pin;
		 		                  GPIOA->BSRR = motor_ra2_Pin;
		 		                  GPIOA->BRR = motor_rb2_Pin;
		 		                  GPIOA->BRR = motor_rb1_Pin;
		 		                  currentstep--;
		 		                  step--;
		 		                  if (step == 0) break;
		 		                  }
		 		                  else if (currentstep % 4 == 3){
		 		                  // Schritt 4
		 		                	  TIM2->CCR4 = PWM;
		 		                  GPIOA->BSRR = motor_rb2_Pin;
		 		                  GPIOA->BRR = motor_rb1_Pin;
		 		                  GPIOC->BRR = motor_ra1_Pin;
		 		                  GPIOA->BRR = motor_ra2_Pin;
		 		                  currentstepr--;
		 		                  stepr--;
		 		                  if (stepr == 0) break;}
		 		                }
		 		              }
		 		     } else {
		 		       // Stoppmodus
		 		    	 TIM2->CCR4 = PWMr;
		 		       GPIOA->BRR = motor_rb2_Pin;
		 		       GPIOA->BRR = motor_rb1_Pin;
		 		       GPIOC->BRR = motor_ra1_Pin;
		 		       GPIOA->BRR = motor_ra2_Pin;

		 		     }
		 		   } else  if (stby==0){
		 		     // Initialisierungssequenz
		 		     TIM2->CCR4 = PWMr;

		 		     GPIOC->BRR = motor_ra1_Pin;
		 		     GPIOA->BSRR = motor_ra2_Pin;
		 		     GPIOA->BRR = motor_rb2_Pin;
		 		     GPIOA->BRR = motor_rb1_Pin;

		 		     GPIOA->BSRR = motor_rb2_Pin;
		 		     GPIOA->BRR = motor_rb1_Pin;
		 		     GPIOC->BRR = motor_ra1_Pin;
		 		     GPIOA->BRR = motor_ra2_Pin;

		 		     GPIOC->BSRR = motor_ra1_Pin;
		 		     GPIOA->BRR = motor_ra2_Pin;
		 		     GPIOA->BRR = motor_rb2_Pin;
		 		     GPIOA->BRR = motor_rb1_Pin;

		 		     GPIOA->BRR = motor_rb2_Pin;
		 		     GPIOA->BSRR = motor_rb1_Pin;
		 		     GPIOC->BRR = motor_ra1_Pin;
		 		     GPIOA->BRR = motor_ra2_Pin;

		 		     TIM2->CCR4 = 0;
		 		     start = 0;
		 		     currentstep = 0;
		 		     GPIOA->BRR = motor_rstby_Pin;
		 		     HAL_Delay(1);
		 		   } else if (start==0){
		 			   TIM2->CCR4 = PWMr;

		 			        GPIOC->BRR = motor_ra1_Pin;
		 			        GPIOA->BSRR = motor_ra2_Pin;
		 			        GPIOA->BRR = motor_rb2_Pin;
		 			        GPIOA->BRR = motor_rb1_Pin;

		 			        GPIOA->BSRR = motor_rb2_Pin;
		 			        GPIOA->BRR = motor_rb1_Pin;
		 			        GPIOC->BRR = motor_ra1_Pin;
		 			        GPIOA->BRR = motor_ra2_Pin;

		 			        GPIOC->BSRR = motor_ra1_Pin;
		 			        GPIOA->BRR = motor_ra2_Pin;
		 			        GPIOA->BRR = motor_rb2_Pin;
		 			        GPIOA->BRR = motor_rb1_Pin;

		 			        GPIOA->BRR = motor_rb2_Pin;
		 			        GPIOA->BSRR = motor_rb1_Pin;
		 			        GPIOC->BRR = motor_ra1_Pin;
		 			        GPIOA->BRR = motor_ra2_Pin;

		 			        TIM2->CCR4 = 0;
		 			        startr = 1;
		 			        currentstepr = 0;
		 		   }
		 	 }
	 }
}



