#include "user.h"

/*		Command Function Template
 *

 NutStatus_e FunctionName(uint8_t *received_data_ptr, uint32_t received_data_length, uint8_t *result_buffer_ptr, uint32_t *result_length,
 uint32_t result_buffer_MAX_size) {
 *result_length = 0;		// length of responding payload


 // return run result: NUT_OK, NUT_WARNING, NUT_ERROR
 return NUT_OK;
 }

 */

NutStatus_e Echo(uint8_t *received_data_ptr, uint32_t received_data_length, uint8_t *result_buffer_ptr, uint32_t *result_length,
		uint32_t result_buffer_MAX_size) {
	uint32_t i;
	uint8_t tempu8;
	*result_length = received_data_length;
	for (i = 0; i < received_data_length; i++) {
		tempu8 = received_data_ptr[i];
		result_buffer_ptr[i] = tempu8;
	}
	return NUT_OK;
}

/* CRACKNUTS LESSONS */
#include <stdlib.h>
#include <string.h>
#define NUM_OF_SECRETS 124
// @formatter:off
char *secrets[NUM_OF_SECRETS] = {
		/* Animals and Nature */
		"Cats have over 100 different vocal sounds, but dogs only have about 10.",
		"Sea otters hold hands when they sleep to keep from drifting apart.",
		"Kangaroos can't walk backward, which is why they symbolize progress in Australia.",
		"Some ants can make themselves explode to defend their colonies.",
		"Male seahorses are the ones that carry babies, not the females!",
		"A group of flamingos is called a \"flamboyance\" — quite fitting, right?",
		"Sloths only poop once a week, and it's an exhausting process for them!",
		"Cows have best friends and get stressed when separated.",
		"A snail can sleep for three years without waking up.",
		"Polar bears have black skin under their thick white fur.",
		"Ducks are known to have regional accents, just like humans.",
		"Parrots can dance to a beat, making them one of the few animals with rhythm.",
		"There are more fake flamingos in the world than real ones.",
		"Turtles can breathe through their butts, thanks to cloacal respiration.",
		"Octopuses have three hearts, with one heart dedicated solely to their brain.",
		/* Food and Drinks */
		"Honey never spoils, and archaeologists have found edible honey in ancient tombs.",
		"Ketchup was sold as medicine in the 1830s for indigestion.",
		"Peanuts are technically legumes, not nuts, and they grow underground.",
		"Pineapples were once so expensive, people rented them for parties to show wealth.",
		"Bubblegum is pink because it was the only food dye available at the time.",
		"Coffee beans are actually seeds of a cherry-like fruit.",
		"Bananas are berries, but strawberries are not.",
		"Apples float in water because they are 25% air.",
		"Pound cake got its name because its recipe called for a pound each of butter, sugar, eggs, and flour.",
		"Carrots were originally purple before they turned orange.",
		"The world's most stolen food is cheese.",
		"Watermelons are classified as both fruit and vegetables.",
		"Lobsters taste with their legs and chew with their stomachs.",
		"Potato chips were invented because of a chef's annoyance with a customer's demands.",
		"The world's largest omelet was over 14,000 pounds and required 145,000 eggs!",
		/* History and Culture */
		"Cleopatra lived closer to the invention of the iPhone than to the building of the Great Pyramids.",
		"George Washington had wooden teeth, but they weren't made of wood; they were actually animal teeth.",
		"Beethoven continued to compose music even after he went deaf.",
		"Albert Einstein was offered the presidency of Israel, but he declined.",
		"The Great Fire of London ended the outbreak of the bubonic plague.",
		"Napoleon was once attacked by a horde of bunnies during a hunting expedition.",
		"Ancient Romans used powdered mouse brains as toothpaste.",
		"Viking men wore makeup to appear more attractive to women.",
		"The shortest war in history was between Britain and Zanzibar; it lasted only 38 minutes.",
		"In the 1800s, dentures were made using real human teeth.",
		"In medieval times, animals were sometimes put on trial for crimes.",
		"King Tut's tomb contained seeds, bread, and wine—he had a snack plan for the afterlife!",
		"The Eiffel Tower can be 15 cm taller during hot days due to metal expansion.",
		"The Roman Emperor Gaius made his horse a senator.",
		"Aristotle believed that eels were \"born of mud\" because he couldn't find their reproductive organs.",
		/* Science and Technology */
		"Water can freeze and boil at the same time in a process called \"triple point\".",
		"Your stomach has to produce a new layer of mucus every two weeks to avoid digesting itself.",
		"Babies are born with 300 bones, but adults have only 206.",
		"Spaghettification is the term for how objects stretch as they approach a black hole.",
		"You have a unique tongue print, much like fingerprints.",
		"There’s a species of jellyfish that can technically live forever.",
		"Humans share about 60% of their DNA with bananas.",
		"Hot water freezes faster than cold water; it’s called the Mpemba effect.",
		"Lightning can actually form into balls, known as ball lightning.",
		"Astronauts \"grow\" in space because of spinal fluid shifting without gravity.",
		"Hiccups are a leftover trait from our evolutionary past, specifically fish gills.",
		"Some mushrooms glow in the dark naturally to attract insects.",
		"There’s enough DNA in your body to stretch from the Earth to the sun and back.",
		"Scientists say that octopuses might be aliens because of their unique DNA.",
		"The first computer \"bug\" was an actual moth stuck in a computer.",
		/* Human Body */
		"You produce about 1 to 2 liters of mucus each day.",
		"Humans are the only species known to blush, a trait unique to social animals.",
		"Your bones are stronger, pound for pound, than steel.",
		"Your brain generates enough electricity to power a small light bulb.",
		"Fingernails grow faster on your dominant hand.",
		"You can’t actually tickle yourself because your brain anticipates it.",
		"Goosebumps are an evolutionary remnant from when humans had more body hair.",
		"You shed about 40 pounds of skin in your lifetime.",
		"The human nose can detect over a trillion different scents.",
		"Babies are born with no kneecaps—they develop between ages 2 and 6.",
		"A single hair can hold up to 100 grams, meaning a full head of hair can support about 12 tons.",
		"The cornea is the only part of your body that doesn’t receive blood.",
		"Humans have about the same number of hair follicles as chimpanzees.",
		"Your body contains enough iron to make a small nail.",
		"People with blue eyes have a single, common ancestor.",
		/* Random Fun */
		"The inventor of the Pringles can is now buried in one.",
		"Every \"c\" in \"Pacific Ocean\" is pronounced differently.",
		"There’s a word for a runny nose caused by eating spicy food: gustatory rhinitis.",
		"Bubble wrap was originally intended to be used as wallpaper.",
		"The shortest war in history lasted 38 minutes.",
		"The majority of your brain is water, roughly 75%.",
		"A jiffy is an actual unit of time, approximately 1/100th of a second.",
		"Humans can’t breathe and swallow at the same time—only babies can do this.",
		"Pigs can get sunburned and need protection from the sun.",
		"Armadillos are bulletproof; even bullets have bounced off them.",
		"If you put grapes in the microwave, they explode and create plasma.",
		"It’s impossible to hum while holding your nose.",
		"Goosebumps are an evolutionary trait meant to scare off predators.",
		"The founder of Match.com lost his girlfriend to a man she met on Match.com.",
		"You are more likely to get a computer virus from visiting religious sites than from adult sites.",
		/* Bonus */
		"Cows have four stomachs but only one true stomach.",
		"The word \"muscle\" comes from Latin for \"little mouse,\" as it was thought muscles looked like mice under the skin.",
		"Elephants are the only animals that can’t jump.",
		"A shrimp’s heart is in its head.",
		"A flock of crows is called a \"murder,\" while a group of owls is a \"parliament\".",
		"Ants can lift objects 50 times their own body weight.",
		"Giraffes have the same number of neck bones as humans—seven.",
		"Penguins propose with pebbles to their partners.",
		"Snakes can \"see\" infrared by sensing heat.",
		"Jellyfish don’t have hearts, brains, or bones.",
		"Dolphins can recognize themselves in mirrors.",
		"Pigeons can identify people by their faces.",
		"Bananas grow upside down toward the sun.",
		"Crocodiles can’t stick their tongues out.",
		"Blue whale hearts are the size of small cars.",
		"Armadillos can hold their breath for up to six minutes.",
		"Flamingos turn pink because of the shrimp they eat.",
		"Some frogs can freeze without dying.",
		"The heart of a shrimp is located in its head.",
		"A bat can eat up to 1,200 mosquitoes in an hour.",
		"Mosquitoes prefer blood type O over other types.",
		"The average American eats 35,000 cookies in their lifetime.",
		"Grapes will catch fire in the microwave due to plasma production.",
		"Rabbits eat their poop as it provides essential nutrients.",
		"The strongest muscle in proportion is the tongue.",
		"Elephants can smell water from up to 12 miles away.",
		"Snails can regenerate their eye stalks.",
		"Sloths take about a month to digest their food.",
		"A cockroach can live without its head for a week.",
		"Only female mosquitoes bite as they need blood for egg production.",
		"Goats have rectangular pupils to improve peripheral vision.",
		"Dolphins sleep with one eye open.",
		"A group of pandas is called an \"embarrassment\".",
		"Squirrels plant thousands of new trees each year simply by forgetting where they bury their acorns.",
};
// @formatter:on

NutStatus_e ReadSecret(uint8_t *received_data_ptr, uint32_t received_data_length, uint8_t *result_buffer_ptr, uint32_t *result_length,
		uint32_t result_buffer_MAX_size) {
	*result_length = 0;		// length of responding payload
	// initialized randomizer
	uint16_t seed;
	if(received_data_length > 1) {
		seed = received_data_ptr[0] | (((uint16_t)received_data_ptr[1]) << 8);
	} else {
		seed = HAL_GetTick() & 0x0FFFF;
	}
	srand(seed);
	uint8_t idx = rand() % NUM_OF_SECRETS;
	*result_length = (uint32_t)strlen(secrets[idx]);
	memcpy(result_buffer_ptr, secrets[idx], *result_length);
	// return run result: NUT_OK, NUT_WARNING, NUT_ERROR
	return NUT_OK;
}

/* User command */
// @formatter:off
NutAction_t command_list[] = {
		{.command=0x0001, .function=Echo},
		{.command=0x0002, .function=ReadSecret},
};
// @formatter:on
uint16_t command_count = sizeof(command_list) / sizeof(command_list[0]);

void User_Init() {
	Nut_LED(1);
	HAL_Delay(200);
	Nut_LED(0);
}
