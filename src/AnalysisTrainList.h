#ifndef BACKYARDBRAINS_ANALYSISVIEWTRAINLIST_H
#define BACKYARDBRAINS_ANALYSISVIEWTRAINLIST_H

#include "widgets/Widget.h"
#include "AnalysisView.h"

namespace BackyardBrains {

class AnalysisTrainList : public Widgets::Widget {
public:
	AnalysisTrainList(std::vector<SpikeTrain> &spikeTrains, Widgets::Widget *parent = NULL);
	int selectedTrain() const;
	sigslot::signal1<int> selectionChange;
private:
	static const int PADDING = 2;
	static const int FIELDW = 30;
	static const int FIELDH = 22;
	std::vector<SpikeTrain> &_spikeTrains;

	int _selectedTrain;

	void paintEvent();
	void mousePressEvent(Widgets::MouseEvent *event);
};

}
#endif
