// Fan Art

#ifndef __FANART_HPP
#define __FANART_HPP

#include <ogcsys.h>
#include <gccore.h>
#include <string>
#include <vector>

#include "config.hpp"
#include "texture.hpp"
#include "gui.hpp"

class CFanartElement
{
public:
	CFanartElement(Config &cfg, const char *dir, int artwork);
	~CFanartElement(void);
	
	void draw();
	void tick();
	
	bool IsValid();
	bool IsAnimationComplete();
	bool ShowOnTop();
private:
	STexture m_art;
	int m_artwork;
	int m_delay;
	int m_event_duration;
	
	int m_x;
	int m_y;
	int m_alpha;
	float m_scaleX;
	float m_scaleY;
	float m_angle;
	
	int m_event_x;
	int m_event_y;
	int m_event_alpha;
	float m_event_scaleX;
	float m_event_scaleY;
	float m_event_angle;
	
	float m_step_x;
	float m_step_y;
	float m_step_alpha;
	float m_step_scaleX;
	float m_step_scaleY;
	float m_step_angle;
	
	bool m_show_on_top;
	
	bool m_isValid;
};

class CFanart
{
public:
	CFanart(void);
	~CFanart(void);
	
	void unload();
	bool load(const char *path, const char *id);
	bool isAnimationComplete();
	bool isLoaded();
	
	void getBackground(STexture &hq, STexture &lq);
	CColor getTextColor(CColor themeTxtColor = CColor(0xFFFFFFFF));
	bool hideCover(int global_hide_cover, int global_show_after_animation);
	void draw(bool allow_front, bool front = true);
	void tick();

private:
	std::vector<CFanartElement> m_elms;

	bool m_animationComplete;
	bool m_loaded;
	Config m_cfg;

	STexture m_bg;
	STexture m_bglq;
};

#endif // __FANART_HPP