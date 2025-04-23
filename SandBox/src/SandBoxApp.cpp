#include <Sulfame.h>
class SandBox : public SulfameEngine::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
};

SulfameEngine::Application* SulfameEngine::CreateApplication()
{
	return new SandBox();
}