#include "structured_point_cloud_chain.h"

void StructuredPointCloudChain::DeleteMemoryBeforeTime(NanoMapTime const& delete_time) {
	while (chain.size() >= 0) {
		NanoMapTime i = chain.at(0).vertex->GetTime(); 
		if ( (i.sec <= delete_time.sec) && (i.nsec < delete_time.nsec) ) {
			chain.pop_front();
		}
		else {
			break;
		}
	}
}

NanoMapKnnReply const StructuredPointCloudChain::KnnQuery(NanoMapKnnArgs const& args) const {
  return NanoMapKnnReply();
}