from tkinter import *
import tkinter.messagebox
from ps_operators import PushSwap
from time import sleep

def fetch_nblst(file_name = "test100.txt"):
	while True:
		try:
			f = open(file_name)
		except IOError:
			print(f"File {file_name} doesn't exist or couldn't be open. Please try again")
		else:
			nbs = f.readline().split()
			res = list ()
			for n in nbs:
				res.append(int(n))
			return res

def fetch_cmds(file_name = "result.txt"):
	res = list()
	with open(file_name) as f:
		for line in f:
			res.append(line.rstrip())
	return res

class TestGui(Tk):

	def __init__(self, __window):
		self.org_cmds = fetch_cmds()
		self.org_list = fetch_nblst()
		self.ps = PushSwap(self.org_list)
		self.cmds = self.org_cmds.copy()
		l = len(self.ps.a)
		if l > 480:
			self.canv_h = 2*l + 50
		else:
			self.canv_h = 500
		l = max(self.ps.a)
		if l > 480:
			self.canv_w = int(l) + 50
		else:
			self.canv_w = 500
		self.ratio_h = int(self.canv_h / len(self.ps.a) - 2)
		if self.ratio_h < 1:
			self.ratio_h = 1
		self.ratio_w = int(self.canv_w / max(self.ps.a))
		self.__window = __window
		ww = self.canv_w * 2 + 10
		wh = self.canv_h + 100
		self.__window.geometry(f"{ww}x{wh}")
		self.__window.title(f"Push_Swap Visualiser {ww}x{wh}")
		self.__window.pack_propagate(0)
		self.menu = Menu(__window)
		self.__window.config(menu=self.menu)
		self.submenu = Menu(self.menu)
		self.submenu.add_command(label="New test", command=self.showtest)
		self.menu.add_cascade(label="First", menu=self.submenu)
		self.submenu.add_separator()
		self.submenu.add_command(label="Quit", command=self.exit_program)
		# create toolbar
		self.toolbar = Frame(__window, bg="blue")
		self.tbut1 = Button(self.toolbar, text="Play", command = self.play_pause)
		self.tbut2 = Button(self.toolbar, text="Reset", command = self.reset_sequence)
		self.tbut3 = Button(self.toolbar, text="Next", command = self.one_step)
		self.tbut1.pack(side=LEFT, padx = 2, pady = 2)
		self.tbut2.pack(side=LEFT, padx = 2, pady = 2)
		self.tbut3.pack(side=LEFT, padx = 2, pady = 2)
		self.toolbar.pack(side = TOP, fill = X)
		self.label1 = Label(self.__window, text = f"Last: None\tNext: {self.cmds}", bd = 1, relief = SUNKEN, anchor = W)
		self.label1.pack(side=BOTTOM, fill = X)
		self.canvaa = Canvas(self.__window, width = self.canv_w, height = self.canv_h, bd=1, relief = GROOVE, bg="black")
		self.canvaa.pack(side = LEFT, padx = 2, pady = 2)
		self.canvab = Canvas(self.__window, width = self.canv_w, height = self.canv_h, bd=1, relief = GROOVE, bg="black")
		self.canvab.pack(side = LEFT, padx = 2, pady = 2)
		self.playback = False
		self.re_draw_stacks()
		
	def showtest(self):
		self.label1.config(text = "You clicked on something!")
	
	def do_nothing(self):
		print("Nothing")

	def show_info(self):
		tkinter.messagebox.showinfo("Program Information", "Created by jnovotny@student.hive.fi")
	
	def exit_program(self):
		answer = tkinter.messagebox.askquestion("Exit", "Are you sure?")
		if answer == "yes":
			self.__window.quit()
	
	def draw_stack_a(self):
		if len(self.ps.a) > 0:
			i = self.canv_h + 2
			for n in reversed(self.ps.a):
				self.canvaa.create_rectangle(0, i, n * self.ratio_w, i - self.ratio_h - 1, fill="green")
				i -= self.ratio_h + 1

	def draw_stack_b(self):
		if len(self.ps.b) > 0:
			i = self.canv_h + 2
			for n in reversed(self.ps.b):
				self.canvab.create_rectangle(0, i, n * self.ratio_w, i - self.ratio_h - 1, fill="green")
				i -= self.ratio_h + 1

	def del_stacks(self):
		self.canvaa.delete(ALL)
		self.canvab.delete(ALL)

	def re_draw_stacks(self):
		self.del_stacks()
		self.draw_stack_a()
		self.draw_stack_b()
		self.canvaa.update()
		self.canvab.update()
	
	def perform_cmd(self):
		if len(self.cmds) > 0:
			c = self.cmds.pop(0)
			if c == "sa": self.ps.sa()
			elif c == "sb": self.ps.sb()
			elif c == "ss": self.ps.ss()
			elif c == "pa": self.ps.pa()
			elif c == "pb": self.ps.pb()
			elif c == "ra": self.ps.ra()
			elif c == "rb": self.ps.rb()
			elif c == "rr": self.ps.rr()
			elif c == "rra": self.ps.rra()
			elif c == "rrb": self.ps.rrb()
			elif c == "rrr": self.ps.rrr()
			return c

	def one_step(self):
		c = self.perform_cmd()
		self.re_draw_stacks()
		self.label1.config(text = f"Last: {c}\tNext: {self.cmds}")
		self.label1.update()
	
	def play_pause(self):
		if self.playback:
			self.playback = False
			self.tbut1.config(text="Play")
		else:
			self.playback = True
			self.tbut1.config(text="Pause")
			self.play_sequence()
	
	def stop_sequence(self):
		self.playback = False
	
	def play_sequence(self):
		while len(self.cmds) > 0 and self.playback:
			self.one_step()
			sleep(0.1)
	
	def reset_sequence(self):
		cont = self.playback
		self.stop_sequence()
		self.cmds = self.org_cmds.copy()
		del(self.ps)
		self.ps = PushSwap(self.org_list)
		self.re_draw_stacks()
		self.playback = cont
	
	def open_file_nb(self):
		cont = self.playback
		self.playback = False
		file_name = tkinter.filedialog.askopenfilename()
		if file_name == NONE:
			self.playback = cont
			return
		else:
			self.org_list = fetch_nblst(file_name)
			self.reset_sequence()

root = Tk()
mine = TestGui(root)
root.mainloop()