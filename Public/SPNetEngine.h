
#pragma once
//#include <NetEngine.h>
// UE4: allow Windows platform types to avoid naming collisions
// this must be undone at the bottom of this file!
#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/PreWindowsApi.h"


#include "CoreMinimal.h"

#include "SPNetEngine.generated.h"

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
UCLASS()
class  ASPNetEngine : public AActor
{
	GENERATED_BODY()


	UFUNCTION(BlueprintCallable, Category = "SPNetEngine")
	void Connect();
	
	UFUNCTION(BlueprintCallable, Category = "SPNetEngine")
	void SendPacket();

	UFUNCTION(BlueprintCallable, Category = "SPNetEngine")
	void RecvPacket();

};








