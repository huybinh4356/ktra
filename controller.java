import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class WebController {

    // ==========================================
    // 1. TRANG HỖ TRỢ (Dùng làm trang chính luôn)
    // ==========================================
    @GetMapping("/")
    public String home() {
        return "redirect:/support"; // Mở localhost:8080 tự động nhảy sang trang hỗ trợ
    }

    @GetMapping("/support")
    public String supportPage() {
        return "support"; // Trả về file support.html
    }

    @PostMapping("/submit-support")
    public String submitSupport(
            @RequestParam String topic, 
            @RequestParam String phone, 
            @RequestParam String message) {
        System.out.println("=== NHẬN YÊU CẦU HỖ TRỢ ===");
        System.out.println("Chủ đề: " + topic);
        System.out.println("SĐT: " + phone);
        System.out.println("Nội dung: " + message);
        return "redirect:/support"; // Gửi xong thì load lại trang cho mới
    }

    // ==========================================
    // 2. TRANG ĐĂNG KÝ TÀI KHOẢN
    // ==========================================
    @GetMapping("/register-account")
    public String accountPage() {
        return "register-account"; // Trả về file register-account.html
    }

    @PostMapping("/submit-account")
    public String submitAccount(
            @RequestParam String username, 
            @RequestParam String password, 
            @RequestParam String dob) {
        System.out.println("=== NHẬN ĐĂNG KÝ TÀI KHOẢN ===");
        System.out.println("Username: " + username);
        System.out.println("Năm sinh: " + dob);
        // Không in password ra console để bảo mật (thực tế đi làm sẽ yêu cầu thế này)
        return "redirect:/register-account";
    }

    // ==========================================
    // 3. TRANG ĐĂNG KÝ DỊCH VỤ
    // ==========================================
    @GetMapping("/register-service")
    public String servicePage() {
        return "register-service"; // Trả về file register-service.html
    }

    @PostMapping("/submit-service")
    public String submitService(
            @RequestParam String plan, 
            @RequestParam String months, 
            @RequestParam String totalPrice) {
        System.out.println("=== NHẬN ĐĂNG KÝ DỊCH VỤ ===");
        System.out.println("Mã gói: " + plan);
        System.out.println("Số tháng: " + months);
        System.out.println("Tổng tiền: " + totalPrice);
        return "redirect:/register-service";
    }

    // ==========================================
    // 4. TRANG THÔNG TIN CÁ NHÂN
    // ==========================================
    @GetMapping("/profile")
    public String profilePage() {
        return "profile"; // Trả về file profile.html
    }

    @PostMapping("/submit-profile")
    public String submitProfile(
            @RequestParam String fullname, 
            @RequestParam String phone, 
            @RequestParam String gender, 
            @RequestParam String address) {
        System.out.println("=== NHẬN CẬP NHẬT HỒ SƠ ===");
        System.out.println("Họ Tên: " + fullname);
        System.out.println("SĐT: " + phone);
        System.out.println("Giới tính: " + gender);
        System.out.println("Địa chỉ: " + address);
        return "redirect:/profile";
    }
}