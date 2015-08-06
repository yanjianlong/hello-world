#coding:utf-8
"""
	Jan.Lonely Yan

"""
import similarity.sim_pearson

DATA_PATH = "D:/MyCoding/DataStore/ml-100k/"

def GetContentLines(file_name):
	fp = open(file_name)
	content_lines = fp.readlines()
	fp.close()
	return content_lines

def GetMoveInfo(path = "u.item"):
	content_lines = GetContentLines(DATA_PATH + path)
	movinfo_dict = {}
	for cur_line in content_lines:
		move_id, move_title = cur_line.split('|')[0:2]
		movinfo_dict[move_id] = move_title
	return movinfo_dict

def GetUserInfo(movinfo_dict, path = "u.data"):
	content_lines = GetContentLines(DATA_PATH + path)
	user_info = {}
	for cur_line in content_lines:
		user_id, move_id, scores, cur_time = cur_line.split('\t')
		cur_user_info = user_info.setdefault(int(user_id), {})
		cur_user_info[movinfo_dict[move_id]] = int(scores)
	return user_info


def GetRecommendations(user_infos, person_uid, sim_function = similarity.sim_pearson.GetSimPearson):
	person_info = user_infos[person_uid]

	total_recommond = {}
	total_sim = {}

	for user_id in user_infos:
		if user_id == person_uid:
			continue

		# caculate similarity
		cur_sim = sim_function(user_infos, person_uid, user_id)
		if cur_sim <= 0:
			continue

		# recommend
		cur_user_info = user_infos[user_id]
		for item_key in cur_user_info:
			if item_key not in person_info or person_info[item_key] == 0:
				total_recommond[item_key] = total_recommond.setdefault(item_key, 0) + cur_user_info[item_key] * cur_sim
				total_sim[item_key] = total_sim.setdefault(item_key, 0) + cur_sim

	result_list = []
	total_recommond_items = total_recommond.items()
	for item_key, recommond in total_recommond_items:
		result_list.append((recommond / total_sim[item_key], item_key))

	result_list.sort()
	result_list.reverse()

	return result_list

def Main():
	# get the data
	move_info_dict = GetMoveInfo()
	user_info = GetUserInfo(move_info_dict)

	# caculate recommendation
	result_list = GetRecommendations(user_info, 196)[0:30]
	print "top50:", result_list
	print "move:", len(move_info_dict), "user:", len(user_info)

if __name__ == "__main__":
	Main()
