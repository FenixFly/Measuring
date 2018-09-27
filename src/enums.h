#pragma once
#include <QObject>

class ENUMS{ 
public:
	enum class FIGUREMODE{ 
		NONE,
		LINE,
		ANGLE,
		ELLIPSE,
	};
	Q_ENUM(FIGUREMODE)
	Q_GADGET
	ENUMS() = delete;
};
typedef ENUMS::FIGUREMODE FMODE;