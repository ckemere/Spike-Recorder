#ifndef BACKYARDBRAINS_ANALYSISVIEW_H
#define BACKYARDBRAINS_ANALYSISVIEW_H

#include "widgets/Widget.h"
#include "engine/SpikeSorter.h"

namespace BackyardBrains {

namespace Widgets {
class Plot;
}
class RecordingManager;
class AnalysisAudioView;
class AnalysisTrainList;

struct SpikeTrain {
	std::vector<int64_t> spikes;
	int16_t upperThresh;
	int16_t lowerThresh;
};

class AnalysisView : public Widgets::Widget {
public:
	AnalysisView(RecordingManager &mngr, Widget *parent = NULL);
private:
	AnalysisAudioView *_audioView;
	RecordingManager &_manager;
	Widgets::Plot *_plot;

	AnalysisTrainList *_trainList;
	std::vector<SpikeTrain> _spikeTrains;

	SpikeSorter _spikeSorter;
	bool _wasThreshMode;
	
	void setPlotData();
	void paintEvent();
	void closePressed();
	void savePressed();
	void addPressed();

	void selectionChanged(int i);
};

}
#endif
