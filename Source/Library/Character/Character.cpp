#include "Character.h"

Character::Character(_In_ const std::filesystem::path& filePath)
	: Model(filePath)
	, m_targetPosition()
	, m_currentPosition({0.0f, 0.0f, 0.0f, 0.0f})
	, m_moveBackForward()
	, m_moveLeftRight()
	, m_currentRotation(DOWN)
    , m_movementSpeed(10.0f)
{
}

void Character::Update(FLOAT deltaTime) {
	Translate((m_targetPosition - m_currentPosition));
    m_currentPosition = m_targetPosition;
}

void Character::HandleInput(const InputDirections& directions, FLOAT deltaTime) {
    if (directions.bFront)
    {
        
        m_moveBackForward += m_movementSpeed*deltaTime;
        m_targetPosition += {0.0f, 0.0f, m_moveBackForward, 0.0f};
        
        if (m_currentRotation != UP) {
            switch (m_currentRotation)
            {
                case RIGHT:
                    RotateYInObjectCoordinate(-90, m_targetPosition);
                    break;
                case DOWN:
                    RotateYInObjectCoordinate(180, m_targetPosition);
                    break;
                case LEFT:
                    RotateYInObjectCoordinate(90, m_targetPosition);
                    break;
                default:
                    break;
            }
        }
        
        m_moveBackForward = 0;
        m_currentRotation = UP;
    }
    else if (directions.bLeft)
    {
        
        m_moveLeftRight -= m_movementSpeed * deltaTime;
        m_targetPosition += {m_moveLeftRight, 0.0f, 0.0f, 0.0f};
        
        
        
        if (m_currentRotation != LEFT) {
            switch (m_currentRotation)
            {
            case UP:
                RotateYInObjectCoordinate(-90, m_targetPosition);
                break;
            case RIGHT:
                RotateYInObjectCoordinate(180, m_targetPosition);
                break;
            case DOWN:
                RotateYInObjectCoordinate(90, m_targetPosition);
                break;
            default:
                break;
            }
        }
        
        m_moveLeftRight = 0;
        m_currentRotation = LEFT;
    }
     else if (directions.bBack)
    {
        
        m_moveBackForward -= m_movementSpeed * deltaTime;
        m_targetPosition += {0.0f, 0.0f, m_moveBackForward, 0.0f};
        
        if (m_currentRotation != DOWN) {
            switch (m_currentRotation)
            {
            case LEFT:
                RotateYInObjectCoordinate(-90, m_targetPosition);
                break;
            case UP:
                RotateYInObjectCoordinate(180, m_targetPosition);
                break;
            case RIGHT:
                RotateYInObjectCoordinate(90, m_targetPosition);
                break;
            default:
                break;
            }
        }
        
        m_currentRotation = DOWN;

        m_moveBackForward = 0;
    }
    else if (directions.bRight)
    {
        
        m_moveLeftRight += m_movementSpeed * deltaTime;
        m_targetPosition += {m_moveLeftRight, 0.0f, 0.0f, 0.0f };
        
        if (m_currentRotation != RIGHT) {
            switch (m_currentRotation)
            {
            case DOWN:  
                RotateYInObjectCoordinate(-90, m_targetPosition);
                break;
            case LEFT:
                RotateYInObjectCoordinate(180, m_targetPosition);
                break;
            case UP:
                RotateYInObjectCoordinate(90, m_targetPosition);
                break;
            default:
                break;
            }
        }
        m_moveLeftRight = 0;
        m_currentRotation = RIGHT;
    }
}