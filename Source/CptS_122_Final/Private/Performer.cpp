#include "Performer.h"
#include "Camera/CameraComponent.h"

// Sets default values
APerformer::APerformer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Sets up the camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void APerformer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APerformer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APerformer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Binds our defined action, "Jump" with the jump function
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	// Binds our defined actions, "MoveForward/MoveRight" with the MoveForward/MoveRight functions
	PlayerInputComponent->BindAxis("MoveForward", this, &APerformer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APerformer::MoveRight);

	// Binds our defined actions, "MouseHorizontal/MouseVertical" with the MouseHorizontal/MouseVertical functions
	PlayerInputComponent->BindAxis("MouseHorizontal", this, &APerformer::MouseHorizontal);
	PlayerInputComponent->BindAxis("MouseVertical", this, &APerformer::MouseVertical);
}

void APerformer::MoveForward(float InputValue)
{
	// Adds input to the function, actually moving the player
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);
}

void APerformer::MoveRight(float InputValue)
{
	// Adds input to the function, actually moving the player
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);
}

void APerformer::MouseHorizontal(float InputValue)
{
	// Adds input to the function, actually moving the player
	AddControllerYawInput(InputValue);
}

void APerformer::MouseVertical(float InputValue)
{
	// Adds input to the function, actually moving the player
	AddControllerPitchInput(InputValue);
}