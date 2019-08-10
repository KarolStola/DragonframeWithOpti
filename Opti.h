class Opti
{
public:
	Opti();
	
	void TurnLedOn();
	void TurnLedOff();
	void SetLedOn(bool Value);

	~Opti();
private:
	static bool IsInitialized;
	
	void EnsureInitialization();
	void Initialize();
	void SetupPins();
	void Cleanup();

	virtual int GetStepsPerRevolution() = 0;
	
	static inline int GetLedPin()					{ return 2;	 }
	static inline int GetShutterReleasePin()		{ return 15; }
	static inline int GetMotorDriverActivationPin()	{ return 4;  }
	static inline int GetMotorStepPin()				{ return 16; }
	static inline int GetMotorDirectionPin()		{ return 17; }
	static inline int GetLeftBumperPin()			{ return 32; }
	static inline int GetRightBumperPin()			{ return 33; }
	static inline int GetBatteryStatusPin()			{ return 35; }
	
	inline int GetBumpValueThreshold()	{ return 5;	 }

	bool IsBumped(int BumperPin);
	bool RightBorderReached();
	bool LeftBorderReached();
};
